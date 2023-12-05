#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string category;  // 新增分类信息

    Contact(const std::string& n, const std::string& phone, const std::string& cat = "Uncategorized")
        : name(n), phoneNumber(phone), category(cat) {}

    Contact() = default;
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void deleteContact(const std::string& name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        contacts.erase(it, contacts.end());
        std::cout << "联系人已删除。" << std::endl;
    }

    Contact searchContact(const std::string& name) {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                return contact;
            }
        }
        return Contact();
    }

    void editContact(const std::string& name, const std::string& newPhoneNumber, const std::string& newCategory) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        if (it != contacts.end()) {
            it->phoneNumber = newPhoneNumber;
            it->category = newCategory;  // 更新分类信息
            std::cout << "联系人信息已编辑。" << std::endl;
        } else {
            std::cout << "未找到联系人。" << std::endl;
        }
    }

    Contact searchContact(int phoneNumber) {
        for (const auto& contact : contacts) {
            if (std::stoi(contact.phoneNumber) == phoneNumber) {
                return contact;
            }
        }
        return Contact();
    }

    void classifyContact(const Contact& contact, const std::string& category = "Uncategorized") {
        // 将联系人的分类信息更新为指定的分类
        auto it = std::find_if(contacts.begin(), contacts.end(), [&contact](const Contact& c) {
            return c.name == contact.name;
        });

        if (it != contacts.end()) {
            it->category = category;
            std::cout << "联系人 " << contact.name << " 已分类为: " << category << std::endl;
        } else {
            std::cout << "未找到联系人。" << std::endl;
        }
    }

    // 新增通过分类查找联系人的函数
    std::vector<Contact> searchContactByCategory(const std::string& category) {
        std::vector<Contact> result;
        for (const auto& contact : contacts) {
            if (contact.category == category) {
                result.push_back(contact);
            }
        }
        return result;
    }
};

int main() {
    ContactManager contactManager;

    int choice;
    do {
        std::cout << "1. 添加联系人\n";
        std::cout << "2. 删除联系人\n";
        std::cout << "3. 搜索联系人\n";
        std::cout << "4. 编辑联系人信息\n";
        std::cout << "5. 分类联系人\n";
        std::cout << "6. 通过分类查找联系人\n";  // 新增选项
        std::cout << "7. 退出\n";
        std::cout << "请选择功能: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phone, category;
                std::cout << "请输入联系人姓名: ";
                std::cin >> name;
                std::cout << "请输入联系人电话号码: ";
                std::cin >> phone;
                std::cout << "请输入联系人分类: ";
                std::cin >> category;
                Contact newContact(name, phone, category);
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
                Contact foundContact = contactManager.searchContact(name);
                if (!foundContact.name.empty()) {
                    std::cout << "找到联系人: " << foundContact.name << ", 电话: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "未找到联系人。" << std::endl;
                }
                break;
            }
            case 4: {
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
            case 5: {
                std::string name, category;
                std::cout << "请输入要分类的联系人姓名: ";
                std::cin >> name;
                std::cout << "请输入分类: ";
                std::cin >> category;
                Contact foundContact = contactManager.searchContact(name);
                if (!foundContact.name.empty()) {
                    contactManager.classifyContact(foundContact, category);
                    std::cout << "联系人已分类。" << std::endl;
                } else {
                    std::cout << "未找到联系人。" << std::endl;
                }
                break;
            }
            case 6: {
                std::string category;
                std::cout << "请输入要查找的分类: ";
                std::cin >> category;
                std::vector<Contact> result = contactManager.searchContactByCategory(category);
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
