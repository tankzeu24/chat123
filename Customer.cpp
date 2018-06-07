#include "Customer.h"

Customer::Customer(int newId,string newName,string newAddress)
{
    setId(newId);
    name=newName;
    address=newAddress;
}

Customer::~Customer()
{
    //dtor
}

Customer::Customer(const Customer &customer)
{
    setId(customer.getId());
    name=customer.getName();
    address=customer.getAddress();
}

Customer& Customer::operator=(const Customer &customer)
{
    if( this != &customer)
    {
       setId(customer.getId());
        name=customer.getName();
        address=customer.getAddress();
    }

    return *this;
}

int Customer::getId() const
{
    return id;
}

void Customer::setId(int newId)
{
    if(newId<=0)
    {
          throw std::invalid_argument("Non-positive id parameter exception");
    }
    id=newId;
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
