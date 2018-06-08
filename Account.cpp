#include "Account.h"

using namespace std;

Account::Account()
{
    iban=owner=amount=0;
}

Account::Account(int newIban, int newOwner,double newAmount)
{
    setIban(newIban);
    setOwner(newOwner);
    setBalance(newAmount);
}
Account::~Account()
{
    //dtor
}
Account::Account(const Account &account)
{
    iban=account.getIban();
    owner=account.getOwner();
    amount=account.getBalance();
}

Account& Account::operator=(const Account &account)
{
    if( this != &account)
    {
        iban=account.getIban();
        owner=account.getOwner();
        amount=account.getBalance();
    }
    return *this;
}

void Account::setIban(int newIban)
{
    if(newIban<=0)
    {
        throw std::invalid_argument("Cannot set IBAN to a number <=0");
    }
    iban=newIban;
}

void Account::setOwner(int newOwner)
{
    if(newOwner<=0)
    {
        throw std::invalid_argument("Cannot set ownerID to number <=0");
    }
    owner=newOwner;

}

void Account::setBalance(double newAmount)
{
    if(newAmount<0.0)
    {
        throw std::invalid_argument("Cannot set balance to <0");
    }
    amount=newAmount;
}

int Account::getIban() const
{
    return iban;

}

int Account::getOwner() const
{
    return owner;

}


double Account::getBalance() const
{
    return amount;
}




void Account::setUnlimitedBalance(double newAmount)
{
    if(newAmount<=0)
    {
        throw std::invalid_argument("Cannot deposit amount <=0");
    }
    amount-=newAmount;
}

void Account::depositHelper(double newAmount)
{
    if(newAmount<=0)
    {
        throw std::invalid_argument("Cannot deposit amount <=0");
    }
    amount+=newAmount;
}


