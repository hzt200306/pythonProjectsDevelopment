#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string category;

    // ���캯�������ڳ�ʼ�� Contact ����
    Contact(const std::string& n, const std::string& phone, const std::string& cat = "δ����")
        : name(n), phoneNumber(phone), category(cat) {}

    // Ĭ�Ϲ��캯��
    Contact() = default;
};

class ContactManager {
private:
    std::vector<Contact> contacts; // �洢��ϵ�˵�����

public:
    // ��ȡ�û��������ϵ����Ϣ
    Contact getUserInputForContact() {
        std::string name, phone, category;
        std::cout << "��������ϵ������: ";
        std::cin >> name;
        std::cout << "��������ϵ�˵绰����: ";
        std::cin >> phone;
        std::cout << "��������ϵ�˷���: ";
        std::cin >> category;

        return Contact(name, phone, category);
    }

    // ������ϵ��
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    // ɾ����ϵ��
    void deleteContact(const std::string& name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        contacts.erase(it, contacts.end());
        std::cout << "��ϵ����ɾ����" << std::endl;
    }

    // ͨ������������ϵ��
    Contact searchContactByName(const std::string& name) {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                return contact;
            }
        }
        return Contact(); // δ�ҵ�ʱ���ؿ� Contact ����
    }

    // ͨ���绰����������ϵ��
    Contact searchContactByPhoneNumber(const int phoneNumber) {
        for (const auto& contact : contacts) {
            if (std::stoi(contact.phoneNumber) == phoneNumber) {
                return contact;
            }
        }
        return Contact(); // δ�ҵ�ʱ���ؿ� Contact ����
    }

    // ͨ�����������ϵ��
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

    // �༭��ϵ����Ϣ
    void editContact(const std::string& name, const std::string& newPhoneNumber, const std::string& newCategory) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
            return c.name == name;
        });

        if (it != contacts.end()) {
            it->phoneNumber = newPhoneNumber;
            it->category = newCategory;
            std::cout << "��ϵ����Ϣ�ѱ༭��" << std::endl;
        } else {
            std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
        }
    }
};

int main() {
    ContactManager contactManager;

    int choice;
    do {
        std::cout << "1. ������ϵ��\n";
        std::cout << "2. ɾ����ϵ��\n";
        std::cout << "3. ������ϵ�ˣ�ͨ��������\n";
        std::cout << "4. ������ϵ�ˣ�ͨ���绰���룩\n";
        std::cout << "5. ������ϵ�ˣ�ͨ�����ࣩ\n";
        std::cout << "6. �༭��ϵ����Ϣ\n";
        std::cout << "7. �˳�\n";
        std::cout << "��ѡ����: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Contact newContact = contactManager.getUserInputForContact();
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
                Contact foundContact = contactManager.searchContactByName(name);
                if (!foundContact.name.empty()) {
                    std::cout << "�ҵ���ϵ��: " << foundContact.name << ", �绰: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
                }
                break;
            }
            case 4: {
                int phoneNumber;
                std::cout << "������Ҫ��������ϵ�˵绰����: ";
                std::cin >> phoneNumber;
                Contact foundContact = contactManager.searchContactByPhoneNumber(phoneNumber);
                if (!foundContact.name.empty()) {
                    std::cout << "�ҵ���ϵ��: " << foundContact.name << ", �绰: " << foundContact.phoneNumber << std::endl;
                } else {
                    std::cout << "δ�ҵ���ϵ�ˡ�" << std::endl;
                }
                break;
            }
            case 5: {
                std::string category;
                std::cout << "������Ҫ��������ϵ�˷���: ";
                std::cin >> category;
                std::vector<Contact> result = contactManager.searchContactByCategory(static_cast<const std::string&>(category));

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
            case 6: {
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
