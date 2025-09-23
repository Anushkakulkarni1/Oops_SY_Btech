#include <iostream>
#include <string>
using namespace std;

class staff {
protected:
    string name, department;
    int id;
public:
    void accept1();
    void display1();
};

class teacher : public staff {
private:
    string subject;
    int experience;
public:
    void accept2();
    void display2();
};

class supportstaff : public staff {
    string areaofsupp;
public:
    void accept3();
    void display3();
};

void staff::accept1() {
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Department: ";
    cin >> department;
    cout << "Enter ID: ";
    cin >> id;
}

void staff::display1() {
    cout << "\nName: " << name;
    cout << "\nDepartment: " << department;
    cout << "\nID: " << id;
}

void teacher::accept2() {
    
    accept1();
    cout << "Enter subject: ";
    cin >> subject;
    cout << "Enter Experience: ";
    cin >> experience;
}

void teacher::display2() {
    display1();
    cout << "\nSubject: " << subject;
    cout << "\nExperience: " << experience << endl;
}

void supportstaff::accept3() {
    
    accept1();
    cout << "Enter area of support: ";
    cin >> areaofsupp;
}

void supportstaff::display3() {
    display1();
    cout << "\nArea of support: " << areaofsupp << endl;
}

int main() {
    int teacherCount,ch, supportCount;
    char yn;
    cout<<"-----------Welcome-----------\n";
    cout << "Enter number of teachers: ";
    cin >> teacherCount;

    teacher teacherArr[teacherCount];  

    cout << "Enter number of support staff: ";
    cin >> supportCount;

    supportstaff supportArr[supportCount]; 

 cout<<"-----------------\n";
    cout<<"      Menu      \n";
    cout<<"-----------------\n";
    cout<<"1.Teacher\n2.Support staff\n";
    cout<<"-----------------\n";
    
    do{
        cout<<"Enter choice: ";
    cin>>ch;
        switch(ch){
            case 1:
            for (int i = 0; i < teacherCount; i++) {
				cout << "-----------------------------------------";
                   cout << "\n---Enter details for teacher " << (i + 1) << "---\n";
                    cout << "-------------------------------------------\n";
                   teacherArr[i].accept2();  } 
                   cout<<"\n----------------------";  
                   cout << "\nAll Teachers:\n";
                   cout<<"----------------------\n";
                   for (int i = 0; i < teacherCount; i++) {
                   cout << "\nTeacher " << (i + 1) << ":";
                   teacherArr[i].display2();  }
                   break;
            case 2: 
                 for (int i = 0; i < supportCount; i++) {
					 cout << "-----------------------------------------";
                  cout << "\n---Enter details for support staff " << (i + 1) << "---\n";
                  cout << "-------------------------------------------\n";
                   supportArr[i].accept3();}
                   cout<<"\n----------------------";  
                   cout << "\nAll Support Staff:\n";
                   cout<<"----------------------\n";
                  for (int i = 0; i < supportCount; i++) {
                  cout << "\nSupport Staff " << (i + 1) << ":";
                  supportArr[i].display3();}

            
        }
        cout<<"\nDo you want to continue: ";
        cin>>yn;
    }while(yn=='y'||yn=='Y');
	
    return 0;
}

