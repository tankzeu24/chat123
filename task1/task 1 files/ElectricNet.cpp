#include "ElectricNet.h"
#include "ElectricDevice.h"
#include "cstring"

#include<iostream>


ElectricNet::ElectricNet()
{
    setMaxConsumpion(100);
    devices=List<ElectricDevice>();
}

ElectricNet::~ElectricNet()
{
    //dtor
}

ElectricNet::ElectricNet( int consumption)
{

    setMaxConsumpion(consumption);
    devices=List<ElectricDevice>();

}




ElectricNet::ElectricNet(const ElectricNet &electricNet)
{

    setMaxConsumpion(electricNet.getMaxConsumption());
    devices=electricNet.getDevices();

}

ElectricNet& ElectricNet::operator=(const ElectricNet &electricNet)
{
    if(this !=&electricNet)
    {
        setMaxConsumpion(electricNet.getMaxConsumption());
        devices=electricNet.getDevices();

    }
    return *this;
}

int ElectricNet::getMaxConsumption() const
{
    return maxConsumption;
}

void ElectricNet::setMaxConsumpion( int newConsumption)
{
    if(newConsumption <=0)
    {
        throw std::invalid_argument("cannot have net with consumption <= 0");

    }
    maxConsumption=newConsumption;

}
const List<ElectricDevice>& ElectricNet::getDevices() const
{
    return devices;
}


int ElectricNet::getTotalConsumption() const
{
    int total=0;
    for( int i=0; i<devices.getSize(); i++)
    {
        total+=devices.getItem(i).getConsumedPower();
    }
    return total;
}
ElectricNet& ElectricNet::operator+=(const ElectricDevice &electricDevice)
{

    if(getTotalConsumption() + electricDevice.getConsumedPower() <= getMaxConsumption()  )
    {
        devices.add(electricDevice);
    }
    else
    {
        cout<<"Adding : "<<electricDevice<<" will overload the network"<<endl;
        //here exception can be thrown too depends if we want to
    }

    return *this;

}

ElectricNet ElectricNet::operator+(const ElectricDevice &electricDevice) const
{
    ElectricNet newNet(*this);
    newNet+=electricDevice;
    return newNet;
}

ElectricNet operator+(const ElectricDevice &electricDevice,const ElectricNet &electricNet)
{
    ElectricNet newNet(electricNet);
    newNet+=electricDevice;
    return newNet;
}

ElectricNet& ElectricNet::operator-=(const ElectricDevice &electricDevice)
{

    //remove the first seen device
    for(int i=0; i<devices.getSize(); i++)
        if(electricDevice.getName() != NULL &&  strcmp(devices[i].getName(),electricDevice.getName())==0 )
        {
            devices.remove(devices[i]);
        }


    return *this;
}


ElectricNet ElectricNet::operator-(const ElectricDevice &electricDevice) const
{

    ElectricNet newNet(*this);
    newNet-=electricDevice;
    return newNet;
}

ElectricNet operator-(const ElectricDevice &electricDevice,const ElectricNet &electricNet)
{
    ElectricNet newNet(electricNet);
    newNet-=electricDevice;
    return newNet;
}


ostream& operator<<(ostream &os,const ElectricNet &electricNet)
{
    os<<"Max consumption is " <<electricNet.getMaxConsumption()<<endl;
    os<<"Devices are : "<<endl;
    for(int i=0; i<electricNet.getDevices().getSize(); i++)
    {
        cout<<electricNet.getDevices()[i];
    }
    return os;
}

ElectricDevice& ElectricNet::operator[](const char* name)
{
    for(int i=0; i<devices.getSize(); i++)
    {
        if(strcmp(devices[i].getName(),name)==0)
        {
            return devices[i];
        }
    }
    throw std::invalid_argument("no such ElectricDevice in the ElectricNet");

}

bool ElectricNet::operator!()
{
    return devices.getSize()>0;
}

ElectricNet& ElectricNet::operator++()
{
    setMaxConsumpion(getMaxConsumption()*2);
    return *this;
}

ElectricNet ElectricNet::operator++(int x)
{
    ElectricNet result(*this);
    ++(*this);
    return result;
}

ElectricNet& ElectricNet::operator--()
{
    int toSetConsumption=getMaxConsumption()/2;

    if(toSetConsumption != 0 && getTotalConsumption() <=toSetConsumption)
    {
        setMaxConsumpion(toSetConsumption);
    }
    return *this;
}

ElectricNet ElectricNet::operator--(int x)
{
    ElectricNet result(*this);
    --(*this);
    return result;
}



