#ifndef BANK_H
#define BANK_H
#include<iostream>
using namespace std;
#include <list>
#include "Customer.h"
#include "Account.h"
#include <vector>
class Bank
{
public:


    Bank(string newName="noName",string newAddress="noAddress",vector<Customer*> newCustomers=vector<Customer*>(),vector<Account*> newAccounts=vector<Account*>());
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
    vector<Customer*> getCustomers() const;
    vector<Account*> getAccounts() const;
    void details() const;


private:
    void createAccount(string accountType,int iban,int ownerid,double amount,double overdraftOrInterest);
    string name;
    string address;
    vector<Customer*> customers;
    vector<Account*> accounts;


};

#endif // BANK_H
