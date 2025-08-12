#include <iostream>
#include<string>
using namespace std;
class bank_account{
    string name;
    int acc_no;
    string acc_type;
    float balance=0;
public:
    //void accept();
    // Parameterized constructor
    bank_account(string n, string acc, int no, int bal);
    void display();
    void deposit();
    void withdraw();
};
/*void bank_account::accept(){
    cout<<"\nEnter Name :";
    cin>>name;
    cout<<"\nEnter Account NO:";
    cin>>acc_no;
    cout<<"\nEnter Account type:";
    cin>>acc_type;
    cout<<"\nEnter Balance:";
    cin>>balance;
}*/

//constructor definition 
bank_account::bank_account(string n, string acct, int ano, int bal) 
{
     name = n;
     acc_type = acct;
     acc_no = ano;
     balance = bal;}


void bank_account:: display(){
    cout<<"\nYour name:"<<name<<endl;
    cout<<"Your Balance:"<<balance<<endl;
    cout<<"Your Account No:"<<acc_no<<endl;
    cout<<"Your account type:"<<acc_type<<endl;
}
void bank_account:: deposit(){
    float amt_dep;
    
     cout<<"\n-----------------------------------\n";
    cout<<"                   Deposit                \n";
    cout<<"----------------------------------------\n";
    cout<<"Your Balance:"<<balance;
    cout<<"\nEnter amount to deposit:";
    cin>>amt_dep;
    balance=balance+amt_dep;
    cout<<"Amount Deposited Successfully!\n";
    cout<<"Current balance:"<<balance<<endl;
    cout<<"----------------------------------------\n";
    
    
}
void bank_account:: withdraw(){
    float amt_with;
    
    cout<<"\n-----------------------------------------\n";
    cout<<"                    Withdraw              \n";
    cout<<"-------------------------------------------\n";
    cout<<"Your Balance: "<<balance<<endl;
    cout<<"Enter amount to withdraw:";
    cin>>amt_with;
    balance=balance-amt_with;
    cout<<"Amount Withdrawed Successfully!\n";
    cout<<"Current balance:"<<balance<<endl;
    cout<<"------------------------------------------\n";
}
int main() {
    string nm, atype;int accno, balance;
    // Take customer details
    cout << "Welcome! Please enter the following details:\n";
    cout << "Enter name of customer:";
    cin >> nm;
    cout << "Enter account type: ";
    cin >> atype;
    cout << "Enter account number: ";
    cin >> accno;
    cout << "Enter current balance: ";
    cin >> balance;
    // Create bank account object
    bank_account obj(nm, atype, accno, balance);
    char ch1;
    int choice;
    
    do{
    
        cout<<"\n___________________________\n";
        cout<<"1.Display 2.Deposit 3.Withdraw\n";
        cout<<"____________________________\n";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1: obj.display();
            break;
            case 2: obj.deposit();
            break;
            case 3: obj.withdraw();
            
        }
    cout<<"\nDo you want to continue(y/n):";
    cin>>ch1;
    }
    while(ch1=='y'||ch1=='Y');
    if (ch1=='N'||ch1=='n'){
        cout<<"Thank you for Banking with us!";
    }
    return 0;
}
