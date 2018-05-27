#include "ElectricDevice.h"
#include<cstring>



ElectricDevice::ElectricDevice() : name(nullptr)
{
    consumedPower=1;
    setStringProperty(name,"NoName");
}

ElectricDevice::~ElectricDevice()
{
    delete[] name;
}


ElectricDevice::ElectricDevice(const char* toCopyName, int toCopyPower) : name(nullptr)
{

    setConsumedPower(toCopyPower);
    setStringProperty(name,toCopyName);

}
ElectricDevice::ElectricDevice(const ElectricDevice &electricDevice) : name(nullptr)
{

    setConsumedPower(electricDevice.getConsumedPower());
    setStringProperty(name,electricDevice.getName());
}

ElectricDevice& ElectricDevice::operator=(const ElectricDevice &electricDevice)
{
    if(this != &electricDevice)
    {
        setConsumedPower(electricDevice.getConsumedPower());
        setStringProperty(name,electricDevice.getName());

    }
    return *this;
}



char* ElectricDevice::getName() const
{
    return name;
}
int ElectricDevice::getConsumedPower() const
{
    return consumedPower;
}

void ElectricDevice::setName(const char* toCopyName)
{
    setStringProperty(name,toCopyName);
}

void ElectricDevice::setConsumedPower(int toCopyConsumedPower)
{

    if( toCopyConsumedPower<=0 )
    {
        throw std::invalid_argument("The device cannot have power <= 0");
    }

    consumedPower=toCopyConsumedPower;

}


ostream& operator<<(ostream &os,const ElectricDevice &electricDevice)
{
    os<<electricDevice.getName()<<" "<<electricDevice.getConsumedPower()<<endl;
    return os;
}

bool ElectricDevice::operator==(const ElectricDevice &electricDevice)
{
    if( getConsumedPower()==electricDevice.getConsumedPower() && strcmp(getName(),electricDevice.getName())==0)
    {
        return true;
    }
    return false;
}

bool ElectricDevice::operator!=(const ElectricDevice &electricDevice)
{
    return !(*this==electricDevice);
}


void ElectricDevice::setStringProperty(char *&prop, const char *toCopyString)
{
    if(toCopyString==NULL)
    {
        throw std::invalid_argument("Cannot set name equal to NULL");
    }
    delete[] prop;
    prop = new char[strlen(toCopyString)+1];
    strcpy(prop, toCopyString);

}

