#include <iostream>
using namespace std;
#include "CurrentAccount.h"
#include "PivilegeAccount.h"
#include <set>
#include "Bank.h"


void listCustomers(Bank &bank)
{
 bank.listCustomers();
}
void addNewCustomer(Bank &bank)
{
    int id;
    cout<<"Enter id"<<endl;
    cin>>id;
    string name;
    cout<<"enter name"<<endl;
    cin.ignore();
    getline(cin,name);
    string address;
    cout<<"enter address"<<endl;
    getline(cin,address,'\n');
    bank.addCustomer(id,name,address);

}

void deleteCustomer(Bank &bank)
{
    int id;
    cout<<"Enter customer id to delete"<<endl;
    cin>>id;
    bank.deleteCustomer(id);
}

void listAllAccounts(Bank &bank)
{
    bank.listAccounts();
}

void listCustomerAccounts(Bank &bank)
{
    int id;
    cout<<"enter id "<<endl;
    cin>>id;
    bank.listCustomerAccount(id);
}

void addnewAccount(Bank &bank)
{

    string accType;
    cout<<"Enter account type: "<<endl;
    cout<<"Enter 1 for CurrentAccount"<<endl;
    cout<<"Enter 2 for PivilegeAccount"<<endl;
    cout<<"Enter 3 for SavingsAccount"<<endl;
    int choice;

    while(choice <0 || choice> 3)
    {
        cout<<"enter valid choice"<<endl;
        cin>>choice;
    }


    switch(choice)
    {
    case 1:
        accType="CurrentAccount";
        break;
    case 2:
        accType="PivilegeAccount";
        break;
    case 3:
        accType="SavingsAccount";
        break;

    }


    int iban,owner;
    double amount;
    cout<<"Enter IBAN"<<endl;
    cin>>iban;
    cout<<"Enter ownerId"<<endl;
    cin>>owner;
    cout<<"Enter amount of money"<<endl;
    cin>>amount;
    int additionalParameters;
    cout<<"Enter additional parameter for interest/overdraft (if needed)"<<endl;
    cin>>additionalParameters;
    bank.addAccount(accType,iban,owner,amount,additionalParameters);
}


void deleteAccount(Bank &bank)
{
    int iban;
    cout<<"enter IBAN"<<endl;
    cin>>iban;
    bank.deleteAccount(iban);

}
void withdrawFromAccount(Bank &bank)
{
    int iban;
    double amount;
    cout<<"Enter IBAN"<<endl;
    cin>>iban;
    cout<<"Enter amount"<<endl;
    cin>>amount;
    bank.withdrawlFromAccount(iban,amount);
}

void depositToAccount(Bank &bank)
{
    int iban;
    double amount;
    cout<<"Enter IBAN"<<endl;
    cin>>iban;
    cout<<"Enter amount"<<endl;
    cin>>amount;
    bank.depositToAccount(iban,amount);
}

void tansfer(Bank &bank)
{
    int fromIBAN,toIBAN;
    double amount;
    cout<<"enter fromIBAN"<<endl;
    cin>>fromIBAN;
    cout<<"enter toIBAN"<<endl;
    cin>>toIBAN;
    cout<<"Enter amount"<<endl;
    cin>>amount;
    bank.transfer(fromIBAN,toIBAN,amount);
}

void DisplayInfoForTheBank(Bank &bank)
{
    bank.details();
}
int main()
{
    Bank bank ("BNB bank","Main street 34");

    while(true)
    {
        cout<<endl;
        cout<<"1 List customers"<<endl;
        cout<<"2 Add new customer"<<endl;
        cout<<"3 Delete customer"<<endl;
        cout<<"4 List all accounts"<<endl;
        cout<<"5 List customer accounts"<<endl;
        cout<<"6 Add new account"<<endl;
        cout<<"7 Delete new Account"<<endl;
        cout<<"8 Withdraw from account"<<endl;
        cout<<"9 Deposit to account"<<endl;
        cout<<"10 Transfer"<<endl;
        cout<<"11 Display info for the bank"<<endl;
        cout<<"12 Quit"<<endl;
        cout<<endl;


        int option;
        cout<<"Enter option :"<<endl;
        cin>>option;
        switch(option)
        {
        case 1:
            listCustomers(bank);
            break;
        case 2:
            addNewCustomer(bank);
            break;
        case 3:
            deleteCustomer(bank);
            break;
        case 4:
            listAllAccounts(bank);
            break;
        case 5:
            listCustomerAccounts(bank);
            break;
        case 6:
            addnewAccount(bank);
            break;
        case 7:
            deleteAccount(bank);
            break;
        case 8:
            withdrawFromAccount(bank);
            break;
        case 9:
            depositToAccount(bank);
            break;
        case 10:
            tansfer(bank);
            break;
        case 11:
            DisplayInfoForTheBank(bank);
            break;
        case 12:
            exit(0);
        default:
            cout<<"Wrong option,try again!"<<endl;
        }
    }


    return 0;
}
