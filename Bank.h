#ifndef BANK_H
#define BANK_H
#include<iostream>
using namespace std;
#include <list>
#include "Customer.h"
#include "Account.h"
class Bank
{
public:


    Bank(string newName="noName",string newAddress="noAddress",list<Customer*> newCustomers=list<Customer*>(),list<Account*> newAccounts=list<Account*>());
    Bank(const Bank &bank);
    Bank& operator=(const Bank &bank);
    virtual ~Bank();


    string getName() const;
    string getAddress() const;
    void addCustomer(int customerId,string name,string address);
    void listCustomers() const;
    void deleteCustomer(int customerId);
    void addAccount(string accountType,int iban,int ownerid,double amount,double overdraftOrInterest);
    void deleteAccount(int iban);
    void listAccounts() const;
    void listCustomerAccount(int customerId) const;
    void transfer(int fromIBAN, int toIBAN, double amount) ;
    void withdrawlFromAccount(int iban,double amount);
    void depositToAccount(int iban,double amount);
    friend ostream& operator<<(ostream &os,const Bank& bank);
    list<Customer*> getCustomers() const;
    list<Account*> getAccounts() const;
    void details() const;
protected:

private:
    void createAccount(string accountType,int iban,int ownerid,double amount,double overdraftOrInterest);
    string name;
    string address;
    list<Customer*> customers;
    list<Account*> accounts;


};

#endif // BANK_H
