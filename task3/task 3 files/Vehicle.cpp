#include "Vehicle.h"
#include<cstring>


Vehicle::Vehicle() : make(nullptr),model(nullptr),color(nullptr)
{

    setMake("No Make");
    setModel("No Model");
    setColor("No Color");
    setYear(0);
    setMileage(0);
}

Vehicle::Vehicle(const char* make,const char* model,const char* color,int year,int mileage):make(nullptr),model(nullptr),color(nullptr)
{
    if (year<1950 || mileage< 0)
    {
        throw std::invalid_argument("wrong parameters for year OR mileage ");
    }
    setMake(make);
    setModel(model);
    setColor(color);
    setYear(year);
    setMileage(mileage);


}
Vehicle::~Vehicle()
{
    delete[] make;
    delete[] model;
    delete[] color;
}

Vehicle::Vehicle(const Vehicle &vehicle) :make(nullptr),model(nullptr),color(nullptr)
{
    setMake(vehicle.getMake());
    setModel(vehicle.getModel());
    setColor(vehicle.getColor());
    setYear(vehicle.getYear());
    setMileage(vehicle.getYear());

}

Vehicle& Vehicle::operator=(const Vehicle &vehicle)
{
    if(this != &vehicle)
    {

        setMake(vehicle.getMake());
        setModel(vehicle.getModel());
        setColor(vehicle.getColor());
        setYear(vehicle.getYear());
        setMileage(vehicle.getYear());

    }
    return *this;
}

ostream& operator<<(ostream &os,const Vehicle &vehicle)
{
    os<<vehicle.getMake()<<","<<vehicle.getModel()<<","<<vehicle.getColor()<<","<<vehicle.getYear()<<","<<vehicle.getMileage();
    return os;
}

char* Vehicle::getMake() const
{
    return make;
}

char* Vehicle::getModel() const
{
    return model;
}

char* Vehicle::getColor() const
{
    return color;
}

int Vehicle::getYear() const
{
    return year;
}

int Vehicle::getMileage() const
{
    return mileage;
}


void Vehicle::setMake(const char* toCopyMake)
{

    setStringProperty(make,toCopyMake);

}
void Vehicle::setModel(const char* toCopyModel)
{
    setStringProperty(model,toCopyModel);

}
void Vehicle::setColor(const char* toCopyColor)
{
    setStringProperty(color,toCopyColor);

}
void Vehicle::setYear(int toCopyYear)
{
    year=toCopyYear;
}
void Vehicle::setMileage(int toCopyMileage)
{
    mileage=toCopyMileage;
}

void Vehicle::details() const
{

}


void Vehicle::setStringProperty(char *&prop, const char *toCopyString)
{
    if(toCopyString != NULL)
    {
        delete[] prop;
        prop = new char[strlen(toCopyString)+1];
        strcpy(prop, toCopyString);
    }
}

