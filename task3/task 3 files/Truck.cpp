#include "Truck.h"
#include "Vehicle.h"


Truck::Truck() : Vehicle()
{
    size=1;
}

Truck::~Truck()
{
    //dtor
}

Truck::Truck(const Truck &truck) : Vehicle(truck)
{
    size=truck.getSize();

}

Truck::Truck(const char* make,const char* model,const char* color,int year,int mileage,int newSize):Vehicle(make,model,color,year,mileage)
{
    setSize(newSize);
}

Truck& Truck::operator=(const Truck &truck)
{
    if(this != &truck)
    {
        Vehicle::operator=(truck);
        setSize(truck.getSize());
    }
    return *this;
}

void Truck::details() const
{
    cout<<"Truck with :"<<(const Vehicle&)*this<<","<<getSize()<<endl;


}

int Truck::getSize() const
{
    return size;
}

void Truck::setSize(int newSize)
{

    if(newSize<=0)
    {
        throw std::invalid_argument("size must be > 0");
    }
    size=newSize;


}
