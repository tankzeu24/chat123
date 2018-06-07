#include "Bank.h"
#include "CurrentAccount.h"
#include "PivilegeAccount.h"
#include "SavingsAccount.h"
#include<algorithm>

Bank::Bank(string newName,string newAddress,list<Customer*> newCustomers,list<Account*> newAccounts)
{
    name=newName;
    address=newAddress;
    customers=newCustomers;
    accounts=newAccounts;
}

Bank::~Bank()
{
    for(list<Customer*>::const_iterator it = customers.begin(); it != customers.end(); ++it)
    {
        delete *it;
    }
    customers.clear();

    for(list<Account*>::const_iterator it = accounts.begin(); it != accounts.end(); ++it)
    {
        delete *it;
    }
    accounts.clear();
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


    bool customerExists = any_of(customers.begin(), customers.end(), [&](const Customer* customer)
    {
        return (*customer).getId() == customerId;
    });
    if(customerExists==false)
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


    customers.remove_if([&](Customer *customer)
    {
        if (customer->getId() == customerId)
        {
            delete customer;
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

    bool customerExists = any_of(customers.begin(), customers.end(), [&](const Customer* customer)
    {
        return (*customer).getId() == ownerid;
    });
    if(customerExists==false)
    {
        throw std::invalid_argument("Not existing user with given ownerid exception !");
    }


    bool bankAccountExists = any_of(accounts.begin(), accounts.end(), [&](const Account* account)
    {
        return (*account).getIban() == iban;
    });
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

    std::list<Account*>::iterator foundAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* c)
    {
        return (*c).getIban() == fromIBAN;
    });
    if(foundAccount!=accounts.end())
    {
        (*foundAccount)->withdraw(amount);
    }

}

void Bank::depositToAccount(int toIBAN,double amount)
{

    std::list<Account*>::iterator foundAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* c)
    {
        return (*c).getIban() == toIBAN;
    });
    if(foundAccount!=accounts.end())
    {
        (*foundAccount)->deposit(amount);
    }


}


void Bank::transfer(int fromIBAN,int toIBAN,double amount)
{

    std::list<Account*>::iterator fromAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* c)
    {
        return (*c).getIban() == fromIBAN;
    });
    std::list<Account*>::iterator toAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* c)
    {
        return (*c).getIban() == toIBAN;
    });

    if(fromAccount !=accounts.end() && toAccount != accounts.end())
    {
        bool operationState=(*fromAccount)->withdraw(amount);
        if(operationState==true)
        {
            (*toAccount)->deposit(amount);
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




void Bank::details() const
{
    cout<<"Bank name : " <<getName()<< ", Bank address " << getAddress()<<endl;
    cout<<"Customers : "<<endl;
    listCustomers();
    cout<<"Accounts : "<<endl;
    listAccounts();
    cout<<"Total accounts : "<<accounts.size()<< " Total clients : "<<customers.size()<<endl;

}


