#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
using namespace std;

class Account
{
public:
    Account();
    Account(int iban,int owner,double amount);
    virtual ~Account();
    Account(const Account &account);
    Account& operator=(const Account &account);


    virtual void deposit(double sum)=0;
    virtual bool withdraw(double amount)=0;
    virtual void display() const =0 ;



    int getIban() const;
    int getOwner() const;
    double getBalance() const;


    void setIban(int newIban);
    void setOwner(int newOwner);
    void setBalance(double newAmount);



protected:
    void depositHelper(double amount);
    void  setUnlimitedBalance(double newAmount);
private:

    int iban;
    int owner;
    double amount;
};

#endif // ACCOUNT_H
