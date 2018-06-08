#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount :public Account
{
public:
    SavingsAccount();
    SavingsAccount(int newIban,int newOwner,double newAmount,double interestRate);
    SavingsAccount(const SavingsAccount &savingsAccount);
    SavingsAccount& operator=(const SavingsAccount &savingsAccount);

    virtual ~SavingsAccount();


    void deposit(double sum);
    bool withdraw(double sum);
    void display() const;


    void setInterestRate(double newInterestRate);
    double getInterestRate() const;
    Account* copy() const;

protected:

private:
    double interestRate;
};

#endif // SAVINGSACCOUNT_H
