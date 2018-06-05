#include "Customer.h"

Customer::Customer(int newId,string newName,string newAddress)
{
    id=newId;
    name=newName;
    address=newAddress;
}

Customer::~Customer()
{
    //dtor
}

Customer::Customer(const Customer &customer)
{
    id=customer.getId();
    name=customer.getName();
    address=customer.getAddress();
}

Customer& Customer::operator=(const Customer &customer)
{
    if( this != &customer)
    {
        id=customer.getId();
        name=customer.getName();
        address=customer.getAddress();
    }

    return *this;
}

int Customer::getId() const
{
    return id;
}

string Customer::getName() const
{
    return name;
}

string Customer::getAddress() const
{

    return address;
}

void Customer::display() const
{
    cout<<"OwnerID : "<<getId()<< ", name: "<<getName()<< ", address: "<<getAddress()<<endl;
}
