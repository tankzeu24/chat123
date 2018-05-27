#include "Motorcycle.h"
#include "Vehicle.h"


Motorcycle::Motorcycle() : Vehicle(),type(nullptr)
{
    setType("touring");
}

Motorcycle::~Motorcycle()
{
    delete[] type;
}

Motorcycle::Motorcycle(const char* make,const char* model,const char* color,int year,int mileage,const char* type) :Vehicle(make,model,color,year,mileage),type(nullptr)
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
    if(validateType(toCopyType)==false)
    {
        throw std::invalid_argument("No matching type found");

    }
    setStringProperty(type,toCopyType);

}

bool Motorcycle::validateType(const char* newType)
{
    for(int i=0; i<CONSTANTS_SIZE; i++)
    {
        if(strcmp(newType,typeConstants[i])==0)
        {
            return true;
        }
    }
    return false;
}
