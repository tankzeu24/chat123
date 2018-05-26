#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
using namespace std;

class Vehicle
{
    public:
        Vehicle();
        virtual ~Vehicle();
        Vehicle(const char* make,const char* model,const char* color,int year,int mileage);
        Vehicle(const Vehicle &vehicle);
        Vehicle& operator=(const Vehicle &vehicle);
        friend ostream& operator<<(ostream &os,const Vehicle &vehicle);

        char* getMake() const;
        char* getModel() const;
        char* getColor() const;
        int getYear() const;
        int getMileage() const;
        void setMake(const char* make);
        void setModel(const char* model);
        void setColor(const char* color);
        void setYear(int year);
        void setMileage(int mileage);

        virtual void details() const ;
          static void setStringProperty(char *&prop, const char *toCopyString);
    protected:

    private:


        void deleteUsedMemory();
        char* make;
        char* model;
        char* color;
        int year;
        int mileage;
};

#endif // VEHICLE_H
