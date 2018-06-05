#include "Bank.h"
#include "CurrentAccount.h"
#include "PivilegeAccount.h"
#include "SavingsAccount.h"


Bank::Bank(string newName,string newAddress,list<Customer*> newCustomers,list<Account*> newAccounts)
{
    name=newName;
    address=newAddress;
    customers=newCustomers;
    accounts=newAccounts;
}

Bank::~Bank()
{
    //dtor
}


Bank::Bank(const Bank &bank)
{

    name=bank.getName();
    address=bank.getAddress();
    customers=bank.getCustomers();
    accounts=bank.getAccounts();
}

Bank& Bank::operator=(const Bank &bank)
{
    if( this != &bank)
    {
        name=bank.getName();
        address=bank.getAddress();
        customers=bank.getCustomers();
        accounts=bank.getAccounts();
    }
    return *this;
}


string Bank::getName() const
{
    return name;
}

string Bank::getAddress() const
{
    return address;
}


void Bank::addCustomer(int customerId,string name,string address)
{


    bool existsCustomer=false;

    for( auto const& customer : customers)
    {
        if(customer->getId()==customerId )
        {
            existsCustomer=true;
            break;
        }
    }
    if(existsCustomer==false)
    {
        customers.push_back(new Customer(customerId,name,address));
    }


}

void Bank::listCustomers() const
{
    for( auto const& customer : customers)
    {
        customer->display();
    }
}

void Bank::deleteCustomer(int customerId)
{


    accounts.remove_if([&](Account *account)
    {
        if (account->getOwner() == customerId)
        {
            delete account;
            return true;
        }
        else
        {
            return false;
        }
    });


    accounts.remove_if([&](Account *account)
    {
        if (account->getOwner() == customerId)
        {
            delete account;
            return true;
        }
        else
        {
            return false;
        }
    });

}

void Bank::addAccount(string accountType,int iban,int ownerid,double amount,double additionalParameter)
{

    bool userExists=false;
    for( auto const& customer : customers)
    {
        if(customer->getId()==ownerid)
        {
            userExists=true;
            break;
        }
    }

    if(userExists==false)
    {
        throw std::invalid_argument("Not existing user with given ownerid exception !");
    }

    bool bankAccountExists=false;
    for( auto const& account: accounts)
    {
        if(account->getIban() ==iban)
        {
            bankAccountExists=true;
            break;
        }
    }
    if(bankAccountExists==true)
    {
        throw std::invalid_argument("Already exists bank account with that IBAN");
    }
    createAccount(accountType,iban,ownerid,amount,additionalParameter);
}

void Bank::deleteAccount(int iban)
{
    accounts.remove_if([&](Account *account)
    {
        if (account->getIban() == iban)
        {
            delete account;
            return true;
        }
        else
        {
            return false;
        }
    });
}

void Bank::listAccounts() const
{
    for( auto const& acc : accounts)
    {
        acc->display();
    }
}

void Bank::listCustomerAccount(int customerId) const
{
    for( auto const& acc : accounts)
    {
        if(acc->getOwner()==customerId)
        {
            acc->display();
        }

    }
}

void Bank::withdrawlFromAccount(int fromIBAN,double amount)
{

    for(list<Account*>::iterator acc =accounts.begin() ; acc != accounts.end(); ++acc)
    {

        if( (*acc)->getIban()==fromIBAN)
        {
            (*acc)->withdraw(amount);
            break;
        }
    }

}

void Bank::depositToAccount(int toIBAN,double amount)
{

    for(list<Account*>::iterator acc =accounts.begin() ; acc != accounts.end(); ++acc)
    {

        if( (*acc)->getIban()==toIBAN)
        {
            (*acc)->deposit(amount);
            break;
        }
    }

}


void Bank::transfer(int fromIBAN,int toIBAN,double amount)
{


    Account* firstAccount;
    Account* secondAccount;
    for(list<Account*>::iterator acc =accounts.begin() ; acc != accounts.end(); ++acc)
    {

        if( (*acc)->getIban()==fromIBAN)
        {

            firstAccount=*acc;


        }
    }

    for(list<Account*>::iterator acc =accounts.begin() ; acc != accounts.end(); ++acc)
    {

        if( (*acc)->getIban()==toIBAN)
        {

            secondAccount=*acc;

        }
    }

    if(firstAccount!= nullptr && secondAccount !=nullptr)
    {

        bool operationState= firstAccount->withdraw(amount);
        if(operationState==true)
        {
            secondAccount->deposit(amount);
        }

    }





}

void Bank::createAccount(string accountType,int iban,int ownerid,double amount,double overdraftOrInterest)
{
    Account* toAddAccount=nullptr;
    if(accountType=="CurrentAccount")
    {
        toAddAccount=new CurrentAccount(iban,ownerid,amount);
    }
    else if(accountType=="PivilegeAccount")
    {
        toAddAccount=new PivilegeAccount(iban,ownerid,amount,overdraftOrInterest);

    }
    else if (accountType=="SavingsAccount")
    {
        toAddAccount=new SavingsAccount(iban,ownerid,amount,overdraftOrInterest);

    }
    else
    {
        throw std::invalid_argument("Invalid account type");
    }
    accounts.push_back(toAddAccount);
}

list<Customer*> Bank::getCustomers() const
{
    return customers;
}
list<Account*> Bank::getAccounts() const
{
    return accounts;
}


ostream& operator<<(ostream &os,const Bank &bank)
{
    os<<bank.getName()<<" "<<bank.getAddress()<<endl;
    for( auto const& acc : bank.getAccounts())
    {
        acc->display();
    }
    for( auto const& customer : bank.getCustomers())
    {
        customer->display();
    }
    return os;
}


void Bank::details() const
{
    cout<<"Bank name : " <<getName()<< ", Bank address " << getAddress()<<endl;
    cout<<"Customers : "<<endl;
    listCustomers();
    cout<<"Accounts : "<<endl;
    listAccounts();
    cout<<"Total accounts : "<<accounts.size()<< " Total clients : "<<customers.size()<<endl;

}


