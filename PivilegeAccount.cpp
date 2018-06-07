#include "PivilegeAccount.h"
#include<iostream>
using namespace std;
#include "Account.h"


PivilegeAccount::PivilegeAccount() :Account() ,overdraft(0.0)
{

}

PivilegeAccount::PivilegeAccount(int newIban,int newOwner,double newAmount,double newOverdraft):Account(newIban,newOwner,newAmount)
{

    overdraft=newOverdraft;
}

PivilegeAccount::PivilegeAccount(const PivilegeAccount &priviligeAccount):Account(priviligeAccount)
{
    overdraft=priviligeAccount.getOverdraft();

}

PivilegeAccount& PivilegeAccount::operator=(const PivilegeAccount &priviligeAccount)
{
    if(this != &priviligeAccount)
    {
        Account::operator=(priviligeAccount);
        overdraft=priviligeAccount.getOverdraft();
    }
    return *this;
}

PivilegeAccount::~PivilegeAccount()
{
    //dtor
}




void PivilegeAccount::deposit(double newAmount)
{
    depositHelper(newAmount);
}


bool PivilegeAccount::withdraw(double newAmount)
{
    if(getBalance()+getOverdraft() < newAmount)
    {
        return false;
    }

    setUnlimitedBalance(newAmount);
    return true;

}



void PivilegeAccount::display() const
{
    cout<<"PivilegeAccount ,IBAN: " << getIban()<< " ,Owner: "<<getOwner()<<" ,Overdraft: "<<getOverdraft()<< " ,Balance: "<<getBalance()<<endl;

}


void PivilegeAccount::setOverdraft(double newOverdraft)
{
    if(newOverdraft<=0)
    {
        throw std::invalid_argument("Illegal newOverdraft parameter");
    }
    overdraft=newOverdraft;
}


double PivilegeAccount::getOverdraft() const
{
    return overdraft;
}
