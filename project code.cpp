#include <iostream>
#include <vector>
#include <list>

using namespace std;
class Contact {
public:
    string name;
    string phone;

    Contact(string n, string p) {
        name = n;
        phone = p;
    }
};
class PhoneBook {
    static const int SIZE = 10;
    vector< list<Contact> > table;
public:

    PhoneBook() {
        table.resize(SIZE);
    }
    int hashFunction(string name) {
        int sum = 0;
        for (int i = 0; i < name.length(); i++) {
            sum += name[i];
        }
        return sum % SIZE;
    }
    void addContact(string name, string phone) {

        int index = hashFunction(name);

        table[index].push_back(Contact(name, phone));

        cout << "Contact Added Successfully!\n";
    }

    void searchContact(string name) {

        int index = hashFunction(name);

        list<Contact>::iterator it;

        for (it = table[index].begin();
             it != table[index].end();
             ++it) {

            if (it->name == name) {

                cout << "\nContact Found!\n";
                cout << "Name  : " << it->name << endl;
                cout << "Phone : " << it->phone << endl;

                return;
            }
        }

        cout << "Contact Not Found!\n";
    }

    void deleteContact(string name) {

        int index = hashFunction(name);

        list<Contact>::iterator it;

        for (it = table[index].begin();
             it != table[index].end();
             ++it) {

            if (it->name == name) {

                table[index].erase(it);

                cout << "Contact Deleted Successfully!\n";

                return;
            }
        }

        cout << "Contact Not Found!\n";
    }

    void displayContacts() {

        cout << "\n===== PHONE BOOK CONTACTS =====\n";

        for (int i = 0; i < SIZE; i++) {

            cout << "Index " << i << " : ";

            list<Contact>::iterator it;

            for (it = table[i].begin();
                 it != table[i].end();
                 ++it) {

                cout << "[" << it->name
                     << " : "
                     << it->phone
                     << "] ";
            }

            cout << endl;
        }
    }
};

int main() {

    PhoneBook pb;

    int choice;

    string name;
    string phone;

    do {

        cout << "\n===== PHONE BOOK MENU =====\n";

        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Display Contacts\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Phone Number: ";
            cin >> phone;

            pb.addContact(name, phone);

            break;

        case 2:

            cout << "Enter Name to Search: ";
            cin >> name;

            pb.searchContact(name);

            break;

        case 3:

            cout << "Enter Name to Delete: ";
            cin >> name;

            pb.deleteContact(name);

            break;

        case 4:

            pb.displayContacts();

            break;

        case 5:

            cout << "Exiting Program...\n";

            break;

        default:

            cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
