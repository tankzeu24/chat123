#include "CurrentAccount.h"
#include "Account.h"




CurrentAccount::CurrentAccount():Account()
{

}


CurrentAccount::CurrentAccount(int newIban,int newOwner,double newAmount): Account(newIban,newOwner,newAmount)
{
    //ctor
}

CurrentAccount::~CurrentAccount()
{
    //dtor
}

CurrentAccount::CurrentAccount(const CurrentAccount& currentAccount) : Account(currentAccount)
{

}

CurrentAccount& CurrentAccount::operator=(const CurrentAccount &currentAccount)
{
    if(this != &currentAccount)
    {
        Account::operator=(currentAccount);

    }
    return *this;
}

void CurrentAccount::deposit(double newAmount)
{
    depositHelper(newAmount);
}

bool CurrentAccount::withdraw(double withdrawAmount)
{
    if( withdrawAmount <=0 || (getBalance() - withdrawAmount)<0 )
    {
        return false;
    }
    setBalance(getBalance()-withdrawAmount);
    return true;
}


void CurrentAccount::display() const
{
    cout<<"CurrentAccount , IBAN: "<<getIban()<<", Owner: "<<getOwner()<<" , Balance: "<<getBalance()<<endl;
}

Account* CurrentAccount::copy() const
{
    return new CurrentAccount(*this);
}
