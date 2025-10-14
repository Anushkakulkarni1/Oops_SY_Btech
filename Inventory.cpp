#include <iostream>
#include <fstream>
using namespace std;

class Inventory {
private:
    string name;
    int id;
    float price;
    int quantity;

public:
    void accept() {
        cout << "Enter Item Name: ";
        getline(cin, name);
        cout << "Enter Item ID: ";
        cin >> id;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cin.ignore(); 
    }

    void display() {
        cout << "\nItem Name: " << name;
        cout << "\nItem ID: " << id;
        cout << "\nPrice: " << price;
        cout << "\nQuantity: " << quantity << endl;
    }

    void writeToFile(ofstream &fout) {
        fout << name << endl;
        fout << id << endl;
        fout << price << endl;
        fout << quantity << endl;
    }

    void readFromFile(ifstream &fin) {
        getline(fin, name);
        fin >> id;
        fin >> price;
        fin >> quantity;
        fin.ignore(); 
    }
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    cin.ignore();

    Inventory items[n]; 

    for (int i = 0; i < n; i++) {
        cout << "\n--- Item " << i + 1 << " ---\n";
        items[i].accept();
    }

    ofstream fout("inventory.txt");
    if (!fout) {
        cout << "Error opening file (writing mode)!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        items[i].writeToFile(fout);
    }
    fout.close();

    cout << "\nRecords written successfully!!!\n";

    ifstream fin("inventory.txt");
    if (!fin) {
        cout << "Error opening file (reading mode)!" << endl;
        return 1;
    }

    cout << "\nRecords from file.....\n";
    for (int i = 0; i < n; i++) {
        items[i].readFromFile(fin);
        items[i].display();
    }

    fin.close();
    return 0;
}

