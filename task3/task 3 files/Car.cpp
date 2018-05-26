#include "Car.h"
#include "Vehicle.h"
#include<iostream>
using namespace std;


Car::Car() : Vehicle()
{
    //ctor
}

Car::~Car()
{
    //dtor
}

Car::Car(const char* make,const char* model,const char* color,int year,int mileage) :Vehicle(make,model,color,year,mileage)
{

}

Car::Car(const Car &car) : Vehicle(car)
{

}

Car& Car::operator=(const Car &car)
{
    if(this != &car)
    {
        Vehicle::operator=(car);

    }
    return *this;
}
void Car::details() const
{
    cout<<"Car with: "<<(const Vehicle&)*this<<endl;
}
