#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
using namespace std;
#include <list>
#include "Account.h"

class Customer
{
public:

    Customer(int id=-1,string name="noName",string address="noAddress");
    Customer(const Customer &customer);
    Customer& operator=(const Customer &customer);
    virtual ~Customer();
    int getId() const;
    string getName() const;
    string getAddress() const;
    void display() const;
    void setId(int newId);
    Customer* copy() const;

private:
    int id;
    string name;
    string address;
};

#endif // CUSTOMER_H
