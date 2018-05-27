#ifndef ELECTRICNET_H
#define ELECTRICNET_H
#include "List.h"
#include "ElectricDevice.h"
class ElectricNet
{
public:
    ElectricNet();
    virtual ~ElectricNet();
    ElectricNet( int maxConsumption);
    ElectricNet(const ElectricNet &electricNet);
    ElectricNet& operator=(const ElectricNet &electricNet);

    int getMaxConsumption() const;
    void setMaxConsumpion( int newConsumption);
    const List<ElectricDevice>& getDevices() const ;

    ElectricNet& operator+=(const ElectricDevice &electricDevice);
    ElectricNet operator+(const ElectricDevice &electricDevice) const;
    friend  ElectricNet operator+(const ElectricDevice &electricDevice,const ElectricNet &electricNet);
    ElectricNet& operator-=(const ElectricDevice &electricDevice);
    ElectricNet operator-(const ElectricDevice &electricDevice) const;
    friend  ElectricNet operator-(const ElectricDevice &electricDevice,const ElectricNet &electricNet);
    friend ostream& operator<<(ostream& os,const ElectricNet &electricNet);
    ElectricDevice& operator[](const char* name);
    bool operator!();
    ElectricNet& operator++();
    ElectricNet operator++(int);
    ElectricNet& operator--();
    ElectricNet operator--(int);
protected:

private:

    int getTotalConsumption() const ;
    int maxConsumption;
    List<ElectricDevice> devices;

};



#endif // ELECTRICNET_H
