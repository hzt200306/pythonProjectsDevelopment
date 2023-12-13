#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string category;

    // 构造函数，用于初始化 Contact 对象
    Contact(const std::string& n, const std::string& phone, const std::string& cat = "未分类")
        : name(n), phoneNumber(phone), category(cat) {}

    // 默认构造函数
    Contact() = default;
};

class ContactManager {
private:
    std::vector<Contact> contacts; // 存储联系人的容器

public:
    // 获取用户输入的联系人信息
    Contact getUserInputForContact() {
        std::string name, phone, category;
        std::cout << "请输入联系人姓名: ";
        std::cin >> name;
        std::cout << "请输入联系人电话号码: ";
        std::cin >> phone;
        std::cout << "请输入联系人分类: ";
        std::cin >> category;

        return Contact(name, phone, category);
    }

    // 添加联系人
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    // 删除联系人
    void deleteContact(const std::string& name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        contacts.erase(it, contacts.end());
        std::cout << "联系人已删除。" << std::endl;
    }

    // 通过姓名搜索联系人
    Contact searchContactByName(const std::string& name) {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                return contact;
            }
        }
        return Contact(); // 未找到时返回空 Contact 对象
    }

    // 通过电话号码搜索联系人
    Contact searchContactByPhoneNumber(const int phoneNumber) {
        for (const auto& contact : contacts) {
            if (std::stoi(contact.phoneNumber) == phoneNumber) {
                return contact;
            }
        }
        return Contact(); // 未找到时返回空 Contact 对象
    }

    // 通过分类查找联系人
    std::vector<Contact> searchContactByCategory(const std::string& category, bool byCategory = true) {
        std::vector<Contact> result;
        if (byCategory) {
            for (const auto& contact : contacts) {
                if (contact.category == category) {
                    result.push_back(contact);
                }
            }
        } else {
            // Code for searching by other criteria if needed
        }
        return result;
    }

    // 编辑联系人信息
    void editContact(const std::string& name, const std::string& newPhoneNumber, const std::string& newCategory) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        if (it != contacts.end()) {
            it->phoneNumber = newPhoneNumber;
            it->category = newCategory;
            std::cout << "联系人信息已编辑。" << std::endl;
        } else {
            std::cout << "未找到联系人。" << std::endl;
        }
    }
};

int main() {
    ContactManager contactManager;

    int choice;
    do {
        std::cout << "1. 添加联系人\n";
        std::cout << "2. 删除联系人\n";
        std::cout << "3. 搜索联系人（通过姓名）\n";
        std::cout << "4. 搜索联系人（通过电话号码）\n";
        std::cout << "5. 搜索联系人（通过分类）\n";
        std::cout << "6. 编辑联系人信息\n";
        std::cout << "7. 退出\n";
        std::cout << "请选择功能: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Contact newContact = contactManager.getUserInputForContact();
                contactManager.addContact(newContact);
                break;
            }
            case 2: {
                std::string name;
                std::cout << "请输入要删除的联系人姓名: ";
                std::cin >> name;
                contactManager.deleteContact(name);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "请输入要搜索的联系人姓名: ";
                std::cin >> name;
                Contact foundContact = contactManager.searchContactByName(name);
                if (!foundContact.name.empty()) {
                    std::cout << "找到联系人: " << foundContact.name << ", 电话: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "未找到联系人。" << std::endl;
                }
                break;
            }
            case 4: {
                int phoneNumber;
                std::cout << "请输入要搜索的联系人电话号码: ";
                std::cin >> phoneNumber;
                Contact foundContact = contactManager.searchContactByPhoneNumber(phoneNumber);
                if (!foundContact.name.empty()) {
                    std::cout << "找到联系人: " << foundContact.name << ", 电话: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "未找到联系人。" << std::endl;
                }
                break;
            }
            case 5: {
                std::string category;
                std::cout << "请输入要搜索的联系人分类: ";
                std::cin >> category;
                std::vector<Contact> result = contactManager.searchContactByCategory(static_cast<const std::string&>(category));

                if (!result.empty()) {
                    std::cout << "找到以下联系人：" << std::endl;
                    for (const auto& contact : result) {
                        std::cout << "姓名: " << contact.name << ", 电话: " << contact.phoneNumber << ", 分类: " << contact.category << std::endl;
                    }
                } else {
                    std::cout << "未找到该分类下的联系人。" << std::endl;
                }
                break;
            }
            case 6: {
                std::string name, newPhone, newCategory;
                std::cout << "请输入要编辑的联系人姓名: ";
                std::cin >> name;
                std::cout << "请输入新的电话号码: ";
                std::cin >> newPhone;
                std::cout << "请输入新的分类: ";
                std::cin >> newCategory;
                contactManager.editContact(name, newPhone, newCategory);
                break;
            }
            case 7: {
                std::cout << "感谢使用，再见！" << std::endl;
                break;
            }
            default:
                std::cout << "无效的选项，请重新选择。" << std::endl;
        }
    } while (choice != 7);

    return 0;
}

