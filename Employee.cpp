#include <iostream>
#include <string>

using namespace std;

class employee_information {
    string name, department, address;
    int emp_id, date;
    int number;
    static int count;

public:
    // Parameterised Constructor
    employee_information(string n, string dp, string add, int id, int dt, int num) {
        name = n;
        department = dp;
        address = add;
        emp_id = id;
        date = dt;
        number = num;
        count++; // Correctly increment count here
        cout << "\nYou are in Parameterised Constructor\n";
    }

    // Default Constructor
    employee_information() {
        name = "Asawari";
        department = "CS";
        address = "Kondwa";
        emp_id = 111;
        date = 07032007;
        number = 987654320;
        count++; // Correctly increment count here
        cout << "You are in Default Constructor\n";
    }

    // Copy Constructor
    employee_information(const employee_information& obj) {
        name = obj.name;
        department = obj.department;
        address = obj.address;
        emp_id = obj.emp_id;
        date = obj.date;
        number = obj.number;
        count++; // Already correct
        cout << "You are in Copy Constructor\n";
    }

    // Destructor
    ~employee_information() {
        cout << "Destructored obj:" << count << endl;
        count--;
    }

    void greet() {
        cout << "\n---Welcome---\n";
        cout << "Employee Name: " << name << endl;
        cout << "Employee Department: " << department << endl;
        cout << "Employee address: " << address << endl;
        cout << "Employee Id: " << emp_id << endl;
        cout << "Employee date of joining: " << date << endl;
        cout << "Employee contact number: " << number << endl;
        // Removed the incorrect count++ from here.
    }

    static void show() {
        cout << "Employee no: " << count << endl;
    }
};

int employee_information::count = 0;

int main() {
    string n, dp, add;
    int id, dt;
    int num;

    cout << "Employee name: ";
    cin.ignore();
    getline(cin, n);

    cout << "Employee Department: ";
    cin >> dp;

    cout << "Employee address: ";
    cin >> add;

    cout << "Employee Id: ";
    cin >> id;

    cout << "Employee joining date (x-y-z as number.): ";
    cin >> dt;

    cout << "Employee contact number: ";
    cin >> num;

    // Create an object using the parameterized constructor
    employee_information obj1(n, dp, add, id, dt, num);
    obj1.greet();
    employee_information::show();

    cout << "\n";

    // Create an object using the default constructor
    employee_information obj2;
    obj2.greet();
    employee_information::show();

    cout << "\n";

    // Create an object using the copy constructor
    employee_information obj3(obj2);
    obj3.greet();
    employee_information::show();

    cout << "\n";

    // Create a dynamic object using the parameterized constructor
    employee_information* ptr = new employee_information(n, dp, add, id, dt, num);
    ptr->greet();
    employee_information::show();        // Display count before destruction of ptr
    delete ptr;                                        // The destructor will be called here
    employee_information::show();       // Display count after destruction of ptr
    cout << "\n\n";
    
    return 0;
}
