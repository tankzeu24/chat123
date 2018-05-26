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





ElectricDevice::ElectricDevice(const char* toCopyName,  int toCopyPower )
{

    setConsumedPower(toCopyPower);
    copyName(toCopyName);

}
ElectricDevice::ElectricDevice(const ElectricDevice &electricDevice)
{

    setConsumedPower(electricDevice.getConsumedPower());
    copyName(electricDevice.getName());
}

ElectricDevice& ElectricDevice::operator=(const ElectricDevice &electricDevice)
{
    if(this != &electricDevice)
    {
        setConsumedPower(electricDevice.getConsumedPower());
        delete[] name;
        copyName(electricDevice.getName());

    }
    return *this;
}

void ElectricDevice::copyName(const char* toCopyName)
{

    if(toCopyName==NULL)
    {
        throw std::invalid_argument("No real name passed");
    }

    int length=strlen(toCopyName);
    name=new char[length+1];
    strcpy(name,toCopyName);


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
    delete[] name;
    copyName(toCopyName);
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


