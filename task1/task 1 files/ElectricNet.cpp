#include "ElectricNet.h"
#include "ElectricDevice.h"
#include "cstring"

#include<iostream>


ElectricNet::ElectricNet()
{
    maxConsumption=100;
    devices=List<ElectricDevice>();
}

ElectricNet::~ElectricNet()
{
    //dtor
}

ElectricNet::ElectricNet( int consumption){

    setConsumption(consumption);
    devices=List<ElectricDevice>();

}


 int ElectricNet::getMaxConsumption() const
{
    return maxConsumption;
}

void ElectricNet::setConsumption( int newConsumption)
{
    if(newConsumption >=0)
    {
          maxConsumption=newConsumption;
    }
    else
    {
         throw std::invalid_argument("cannot have net with consumption = 0");
    }

}
List<ElectricDevice> ElectricNet::getDevices() const
{
    return devices;
}

ElectricNet::ElectricNet(const ElectricNet &electricNet)
{

    maxConsumption=electricNet.getMaxConsumption();
    devices=electricNet.getDevices();

}

ElectricNet& ElectricNet::operator=(const ElectricNet &electricNet)
{
    if(this !=&electricNet)
    {
        maxConsumption=electricNet.getMaxConsumption();
        devices=electricNet.getDevices();

    }
    return *this;
}

 int ElectricNet::getTotalConsumption() const
{
     int total=0;
    for( int i=0;i<devices.getSize();i++)
    {
        total+=devices.getItem(i).getConsumedPower();
    }
    return total;
}
ElectricNet& ElectricNet::operator+=(const ElectricDevice &electricDevice)
{

        if(getTotalConsumption() + electricDevice.getConsumedPower() <= getMaxConsumption() && electricDevice != NULL )
        {
            devices.add(electricDevice);
        }
        else
        {
            cout<<"Adding :"<<electricDevice<<" will overload the network"<<endl;
        }



        return *this;

}

ElectricNet& ElectricNet::operator+(const ElectricDevice &electricDevice)
{
    return *this+=electricDevice;
}


ElectricNet& ElectricNet::operator-=(const ElectricDevice &electricDevice)
{
    if(&electricDevice != NULL){

    for(int i=0;i<devices.getSize();i++)
        if(electricDevice.getName() != NULL &&  strcmp(devices[i].getName(),electricDevice.getName())==0 )
        {
            devices.remove(devices[i]);
        }
    }

    return *this;
}


  ElectricNet& ElectricNet::operator-(const ElectricDevice &electricDevice){

            return *this -=electricDevice;
  }

ostream& operator<<(ostream &os,const ElectricNet &electricNet)
{
    os<<"Max consumption is " <<electricNet.getMaxConsumption()<<endl;
    os<<"Devices are : "<<endl;
    for(int i=0;i<electricNet.getDevices().getSize();i++)
    {
        cout<<electricNet.getDevices()[i];
    }
    return os;
}

ElectricDevice& ElectricNet::operator[](const char* name)
{
    for(int i=0;i<devices.getSize();i++)
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
    if(devices.getSize()>0)
    {
        return true;
    }
    return false;
}

ElectricNet& ElectricNet::operator++()
{
        setConsumption(getMaxConsumption()*2);
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

      if(getTotalConsumption() <=toSetConsumption)
      {
          setConsumption(toSetConsumption);
      }
        return *this;
}

ElectricNet ElectricNet::operator--(int x)
{
    ElectricNet result(*this);
    --(*this);
    return result;
}



