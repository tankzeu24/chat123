#include "ElectricDevice.h"
#include<cstring>



ElectricDevice::ElectricDevice()
{
    consumedPower=1;
    copyName("Default Name");
}

ElectricDevice::~ElectricDevice()
{
    delete[] name;
}

void ElectricDevice::copyName(const char* toCopyName)
{
    if( toCopyName != NULL)
    {
    int length=strlen(toCopyName);
    name=new char[length+1];
    strcpy(name,toCopyName);
    }
    else
    {
        throw std::invalid_argument("No real name passed");
    }

}

ElectricDevice::ElectricDevice(const char* toCopyName ,  int toCopyPower )
{
    if( toCopyPower>0){


    consumedPower=toCopyPower;
    copyName(toCopyName);
    }
    else
    {
         throw std::invalid_argument("The device cannot have power = 0");
    }
}
ElectricDevice::ElectricDevice(const ElectricDevice &electricDevice)
{

    consumedPower=electricDevice.getConsumedPower();
    copyName(electricDevice.getName());
}

ElectricDevice& ElectricDevice::operator=(const ElectricDevice &electricDevice)
{
    if(this != &electricDevice)
    {
        consumedPower=electricDevice.getConsumedPower();
        delete[] name;
        copyName(electricDevice.getName());

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
    copyName(toCopyName);
}

void ElectricDevice::setConsumedPower(int toCopyConsumedPower)
{
    consumedPower=toCopyConsumedPower;
}

ostream& operator<<(ostream &os,const ElectricDevice &electricDevice)
{
    os<<electricDevice.getName()<<" "<<electricDevice.getConsumedPower()<<endl;
    return os;
}

bool ElectricDevice::operator==(const ElectricDevice &electricDevice)
{
    if(strcmp(getName(),electricDevice.getName())==0 && getConsumedPower()==electricDevice.getConsumedPower())
    {
        return true;
    }
    return false;
}

bool ElectricDevice::operator!=(const ElectricDevice &electricDevice)
{
    return !(*this==electricDevice);
}


