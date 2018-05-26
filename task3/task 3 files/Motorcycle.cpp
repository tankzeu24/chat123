#include "Motorcycle.h"
#include "Vehicle.h"


Motorcycle::Motorcycle() : Vehicle(),type(nullptr)
{
    setType("No Type");
}

Motorcycle::~Motorcycle()
{
    delete[] type;
}

Motorcycle::Motorcycle(const char* make,const char* model,const char* color,int year,int mileage,const char* type) :Vehicle(make,model,color,year,mileage) ,type(nullptr)
{
    setType(type);
}
Motorcycle::Motorcycle(const Motorcycle &motorcycle) : Vehicle(motorcycle),type(nullptr)
{
   setType(motorcycle.getType());
}

Motorcycle& Motorcycle::operator=(const Motorcycle &motorcycle)
{
    if(this != &motorcycle)
    {
        Vehicle::operator=(motorcycle);
        setType(motorcycle.getType());
    }
    return *this;
}

void Motorcycle::details() const
{
    cout<<"Motorcycle with :"<<(const Vehicle&)*this<<","<<getType()<<endl;


}
char* Motorcycle::getType() const
{
    return type;
}

void Motorcycle::setType(const char* toCopyType)
{
    setStringProperty(type,toCopyType);
}
