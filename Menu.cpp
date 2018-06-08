#include "Menu.h"

Menu::Menu()
{
    bank=Bank();
}

Menu::~Menu()
{
    //dtor
}

Menu::Menu(const Bank &newBank)
{
    bank=newBank;
}

Menu& Menu::operator=(const Menu &menu)
{
    if(this != &menu)
    {
        bank=menu.getBank();
    }
    return *this;
}

void Menu::displayMainMenu() const
{
    cout<<endl;
    cout<<"1 List customers"<<endl;
    cout<<"2 Add new customer"<<endl;
    cout<<"3 Delete customer"<<endl;
    cout<<"4 List all accounts"<<endl;
    cout<<"5 List customer accounts"<<endl;
    cout<<"6 Add new account"<<endl;
    cout<<"7 Delete  Account"<<endl;
    cout<<"8 Withdraw from account"<<endl;
    cout<<"9 Deposit to account"<<endl;
    cout<<"10 Transfer"<<endl;
    cout<<"11 Display info for the bank"<<endl;
    cout<<"12 Quit"<<endl;
    cout<<endl;
}


void Menu::chooseOption()
{
    int option;
    cout<<"Enter option :"<<endl;
    cin>>option;
    switch(option)
    {
    case 1:
        listCustomers();
        break;
    case 2:
        addNewCustomer();
        break;
    case 3:
        deleteCustomer();
        break;
    case 4:
        listAllAccounts();
        break;
    case 5:
        listCustomerAccounts();
        break;
    case 6:
        addnewAccount();
        break;
    case 7:
        deleteAccount();
        break;
    case 8:
        withdrawFromAccount();
        break;
    case 9:
        depositToAccount();
        break;
    case 10:
        tansfer();
        break;
    case 11:
        displayInfoForTheBank();
        break;
    case 12:
        exit(0);
    default:
        cout<<"Wrong option,try again!"<<endl;
    }
}

Bank Menu::getBank() const
{
    return bank;
}

void Menu::start()
{
    while(true)
    {


        displayMainMenu();
        chooseOption();
    }
}




void Menu::listCustomers() const
{
    bank.listCustomers();
}
void Menu::addNewCustomer()
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

void Menu::deleteCustomer()
{
    int id;
    cout<<"Enter customer id to delete"<<endl;
    cin>>id;
    bank.deleteCustomer(id);
}

void Menu::listAllAccounts() const
{
    bank.listAccounts();
}

void Menu::listCustomerAccounts() const
{
    int id;
    cout<<"enter id "<<endl;
    cin>>id;
    bank.listCustomerAccount(id);
}




void Menu::addnewAccount()
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


void Menu::deleteAccount()
{
    int iban;
    cout<<"enter IBAN"<<endl;
    cin>>iban;
    bank.deleteAccount(iban);

}
void Menu::withdrawFromAccount()
{
    int iban;
    double amount;
    cout<<"Enter IBAN"<<endl;
    cin>>iban;
    cout<<"Enter amount"<<endl;
    cin>>amount;
    bank.withdrawlFromAccount(iban,amount);
}

void Menu::depositToAccount()
{
    int iban;
    double amount;
    cout<<"Enter IBAN"<<endl;
    cin>>iban;
    cout<<"Enter amount"<<endl;
    cin>>amount;
    bank.depositToAccount(iban,amount);
}

void Menu::tansfer()
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

void Menu::displayInfoForTheBank() const
{
    bank.details();
}

