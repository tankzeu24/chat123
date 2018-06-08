#include "Bank.h"
#include "CurrentAccount.h"
#include "PivilegeAccount.h"
#include "SavingsAccount.h"
#include <algorithm>
#include <list>
#include <vector>

Bank::Bank(string newName,string newAddress,vector<Customer*> newCustomers,vector<Account*> newAccounts)
{
    name=newName;
    address=newAddress;
    customers=newCustomers;
    accounts=newAccounts;
}

Bank::~Bank()
{
    for(vector<Customer*>::const_iterator it = customers.begin(); it != customers.end(); ++it)
    {
        delete *it;
    }
    for(vector<Account*>::const_iterator it = accounts.begin(); it != accounts.end(); ++it)
    {
        delete *it;
    }
}


Bank::Bank(const Bank &bank)
{

    name=bank.getName();
    address=bank.getAddress();

    for( auto const& customer : bank.getCustomers())
    {
        customers.push_back(customer->copy());
    }
    for( auto const& account : bank.getAccounts())
    {
        accounts.push_back(account->copy());
    }

}

Bank& Bank::operator=(const Bank &bank)
{
    if( this != &bank)
    {
        name=bank.getName();
        address=bank.getAddress();
        for( auto const& customer : bank.getCustomers())
        {
            customers.push_back(customer->copy());
        }
        for( auto const& account : bank.getAccounts())
        {
            accounts.push_back(account->copy());
        }
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
        return customer->getId() == customerId;
    });
    if(!customerExists)
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


    customers.erase( std::remove_if(customers.begin(),customers.end(),[&](Customer *customer)
    {
        if(customer->getId()==customerId)
        {
            delete customer;
            return true;
        }
        return false;
    }),customers.end());


    /*
        OLD IMPLEMENTATION
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
    */

    accounts.erase( std::remove_if(accounts.begin(),accounts.end(),[&](Account *account)
    {
        if(account->getOwner()==customerId)
        {
            delete account;
            return true;
        }
        return false;
    }),accounts.end());


    /*    OLD IMPLEMENTATION
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
    */

}

void Bank::addAccount(string accountType,int iban,int ownerid,double amount,double additionalParameter)
{

    bool customerExists = any_of(customers.begin(), customers.end(), [&](const Customer* customer)
    {
        return customer->getId() == ownerid;
    });
    if(!customerExists)
    {
        throw std::invalid_argument("Not existing user with given ownerid exception !");
    }


    bool bankAccountExists = any_of(accounts.begin(), accounts.end(), [&](const Account* account)
    {
        return account->getIban() == iban;
    });
    if(bankAccountExists)
    {
        throw std::invalid_argument("Already exists bank account with that IBAN");
    }

    createAccount(accountType,iban,ownerid,amount,additionalParameter);
}

void Bank::deleteAccount(int iban)
{
    accounts.erase( std::remove_if(accounts.begin(),accounts.end(),[&](Account *account)
    {
        if(account->getIban()==iban)
        {
            delete account;
            return true;
        }
        return false;
    }),accounts.end());

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

    vector<Account*>::iterator foundAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* account)
    {
        return account->getIban() == fromIBAN;
    });
    if(foundAccount!=accounts.end())
    {
        (*foundAccount)->withdraw(amount);
    }

}

void Bank::depositToAccount(int toIBAN,double amount)
{

    vector<Account*>::iterator foundAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* account)
    {
        return account->getIban() == toIBAN;
    });
    if(foundAccount!=accounts.end())
    {
        (*foundAccount)->deposit(amount);
    }


}


void Bank::transfer(int fromIBAN,int toIBAN,double amount)
{

    vector<Account*>::iterator fromAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* account)
    {
        return (*account).getIban() == fromIBAN;
    });
    vector<Account*>::iterator toAccount = find_if(accounts.begin(), accounts.end(), [&](const Account* account)
    {
        return (*account).getIban() == toIBAN;
    });

    if(fromAccount !=accounts.end() && toAccount != accounts.end())
    {
        bool operationState=(*fromAccount)->withdraw(amount);
        if(operationState)
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

vector<Customer*> Bank::getCustomers() const
{
    return customers;
}
vector<Account*> Bank::getAccounts() const
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


