#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<int, string> mapType;

void display(const mapType &m) {
    if (m.empty()) {
        cout << "\nNo records found.\n";
        return;
    }
    cout << "\n--- Student Records (PRN : Name) ---\n";
    for (auto &p : m) {
        cout << p.first << " : " << p.second << endl;
    }
    cout << "Total students: " << m.size() << endl;
}

int main() {
    mapType populationMap;
    int choice;

    do {
        cout << "\n=========== MENU ===========\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Student by PRN\n";
        cout << "4. Update Student Name\n";
        cout << "5. Delete Student by PRN\n";
        cout << "6. Clear All Records\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int prn;
            string name;
            cout << "Enter PRN: ";
            cin >> prn;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            populationMap[prn] = name;
            cout << "Record Inserted Successfully!\n";
            break;
        }

        case 2:
            display(populationMap);
            break;

        case 3: {
            int prn;
            cout << "Enter PRN to search: ";
            cin >> prn;

            auto it = populationMap.find(prn);
            if (it != populationMap.end())
                cout << prn << " belongs to " << it->second << endl;
            else
                cout << "PRN not found.\n";
            break;
        }

        case 4: {
            int prn;
            cout << "Enter PRN to update: ";
            cin >> prn;

            auto it = populationMap.find(prn);
            if (it != populationMap.end()) {
                string newName;
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, newName);
                it->second = newName;
                cout << "Record updated successfully!\n";
            } else {
                cout << "PRN not found!\n";
            }
            break;
        }

        case 5: {
            int prn;
            cout << "Enter PRN to delete: ";
            cin >> prn;
            if (populationMap.erase(prn))
                cout << "Record deleted successfully.\n";
            else
                cout << "PRN not found!\n";
            break;
        }

        case 6:
            populationMap.clear();
            cout << "All records cleared!\n";
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
