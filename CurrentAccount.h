#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include "Account.h"



class CurrentAccount :public Account
{
public:
    CurrentAccount();
    CurrentAccount(int newIban,int newOwner, double newAmount);
    CurrentAccount(const CurrentAccount &currentAccount);
    CurrentAccount& operator=(const CurrentAccount& currentAccount);
    virtual ~CurrentAccount();


    void deposit(double sum);
    bool withdraw(double sum);
    void display() const;

    Account* copy() const;


protected:

private:
};

#endif // CURRENTACCOUNT_H
