#ifndef TRUCK_H
#define TRUCK_H
#include<iostream>
#include "Vehicle.h"
using namespace std;

class Truck : public  Vehicle
{
public:
    Truck();
    virtual ~Truck();
    Truck(const Truck &truck);
    Truck(const char* make,const char* model,const char* color,int year,int mileage,int size);
    Truck& operator=(const Truck &trick);
    void details() const;

protected:

private:
    int getSize() const;
    void setSize(int sizeToCopy);
    int size;
};

#endif // TRUCK_H
