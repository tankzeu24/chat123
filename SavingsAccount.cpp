#include "SavingsAccount.h"
#include "Account.h"


SavingsAccount::SavingsAccount(): Account(),interestRate(0.0)
{

}
SavingsAccount::SavingsAccount(int newIban,int newOwner,double newAmount,double newInterestRate) :Account(newIban,newOwner,newAmount)
{
    setInterestRate(newInterestRate);

}

SavingsAccount::SavingsAccount(const SavingsAccount &savingsAccount) : Account(savingsAccount)
{
    interestRate=savingsAccount.getInterestRate();

}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount &savingsAccount)
{
    if(this != &savingsAccount)
    {
        Account::operator=(savingsAccount);
        interestRate=savingsAccount.getInterestRate();
    }
    return *this;
}
SavingsAccount::~SavingsAccount()
{
    //dtor
}

void SavingsAccount::deposit(double newAmount)
{
    depositHelper(newAmount);
}

bool SavingsAccount::withdraw(double withdrawAmount)
{
    if( withdrawAmount <=0 || (getBalance() -withdrawAmount)<0 )
    {
        return false;
    }
    setBalance(getBalance()-withdrawAmount);
    return true;
}



void SavingsAccount::display() const

{

    cout<<"SavingsAccount , IBAN: " << getIban()<< " ,Owner : "<<getOwner()<< " ,Interest Rate : "<<getInterestRate()<< " ,Balance : "<<getBalance()<<endl;


}




void SavingsAccount::setInterestRate(double newInterestRate)
{
    if(newInterestRate<=0.0 || newInterestRate >100.0)
    {
        throw std::invalid_argument("Illegal interestRate argument " );
    }
    interestRate=newInterestRate;
}

double SavingsAccount::getInterestRate() const
{
    return interestRate;
}

Account* SavingsAccount::copy() const
{
    return new SavingsAccount(*this);
}
