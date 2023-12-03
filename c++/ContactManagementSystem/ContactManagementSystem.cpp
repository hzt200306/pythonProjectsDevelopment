#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string category;  // ����������Ϣ

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
        std::cout << "��ϵ����ɾ����" << std::endl;
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
            it->category = newCategory;  // ���·�����Ϣ
            std::cout << "��ϵ����Ϣ�ѱ༭��" << std::endl;
        } else {
            std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
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
        // ����ϵ�˵ķ�����Ϣ����Ϊָ���ķ���
        auto it = std::find_if(contacts.begin(), contacts.end(), [&contact](const Contact& c) {
            return c.name == contact.name;
        });

        if (it != contacts.end()) {
            it->category = category;
            std::cout << "��ϵ�� " << contact.name << " �ѷ���Ϊ: " << category << std::endl;
        } else {
            std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
        }
    }

    // ����ͨ�����������ϵ�˵ĺ���
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
        std::cout << "1. �����ϵ��\n";
        std::cout << "2. ɾ����ϵ��\n";
        std::cout << "3. ������ϵ��\n";
        std::cout << "4. �༭��ϵ����Ϣ\n";
        std::cout << "5. ������ϵ��\n";
        std::cout << "6. ͨ�����������ϵ��\n";  // ����ѡ��
        std::cout << "7. �˳�\n";
        std::cout << "��ѡ����: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phone, category;
                std::cout << "��������ϵ������: ";
                std::cin >> name;
                std::cout << "��������ϵ�˵绰����: ";
                std::cin >> phone;
                std::cout << "��������ϵ�˷���: ";
                std::cin >> category;
                Contact newContact(name, phone, category);
                contactManager.addContact(newContact);
                break;
            }
            case 2: {
                std::string name;
                std::cout << "������Ҫɾ������ϵ������: ";
                std::cin >> name;
                contactManager.deleteContact(name);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "������Ҫ��������ϵ������: ";
                std::cin >> name;
                Contact foundContact = contactManager.searchContact(name);
                if (!foundContact.name.empty()) {
                    std::cout << "�ҵ���ϵ��: " << foundContact.name << ", �绰: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
                }
                break;
            }
            case 4: {
                std::string name, newPhone, newCategory;
                std::cout << "������Ҫ�༭����ϵ������: ";
                std::cin >> name;
                std::cout << "�������µĵ绰����: ";
                std::cin >> newPhone;
                std::cout << "�������µķ���: ";
                std::cin >> newCategory;
                contactManager.editContact(name, newPhone, newCategory);
                break;
            }
            case 5: {
                std::string name, category;
                std::cout << "������Ҫ�������ϵ������: ";
                std::cin >> name;
                std::cout << "���������: ";
                std::cin >> category;
                Contact foundContact = contactManager.searchContact(name);
                if (!foundContact.name.empty()) {
                    contactManager.classifyContact(foundContact, category);
                    std::cout << "��ϵ���ѷ��ࡣ" << std::endl;
                } else {
                    std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
                }
                break;
            }
            case 6: {
                std::string category;
                std::cout << "������Ҫ���ҵķ���: ";
                std::cin >> category;
                std::vector<Contact> result = contactManager.searchContactByCategory(category);
                if (!result.empty()) {
                    std::cout << "�ҵ�������ϵ�ˣ�" << std::endl;
                    for (const auto& contact : result) {
                        std::cout << "����: " << contact.name << ", �绰: " << contact.phoneNumber << ", ����: " << contact.category << std::endl;
                    }
                } else {
                    std::cout << "δ�ҵ��÷����µ���ϵ�ˡ�" << std::endl;
                }
                break;
            }
            case 7: {
                std::cout << "��лʹ�ã��ټ���" << std::endl;
                break;
            }
            default:
                std::cout << "��Ч��ѡ�������ѡ��" << std::endl;
        }
    } while (choice != 7);

    return 0;
}
