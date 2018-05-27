#include <iostream>

using namespace std;
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"
int main()
{

    Vehicle defaultVehicle;
    cout<<"Default vehicle : (expected nothing) "<<endl;
    defaultVehicle.details();
    cout<<"Default car : "<<endl;
     Car defaultCar;
    defaultCar.details(); //shows default values
    cout<<"Default truck : "<<endl;
    Truck defaultTruck;
    defaultTruck.details();
    cout<<"Default motorcycle : " <<endl;
    Motorcycle defaultMotorcycle;
    defaultMotorcycle.details();
     cout<<"=========="<<endl;

    Vehicle v=Vehicle("some Model","some brand","some color",1999,99);
    v.details(); //expected nothing in the console
    Car car=Car("Porche","Best","Red",2000,100);
    car.details(); //shows the details

    Truck truck=Truck("KMZ","Top","Blue",1990,50,200);
    truck.details();

    Motorcycle motorcycle=Motorcycle("BMX","nice","Green",2001,20,"touring");
    motorcycle.details();

    cout<<"=========="<<endl;
    cout<<"Example using virtual function : "<<endl;
    Vehicle* vehicles[]= {&v,&car,&truck,&motorcycle};
    for(int i=0; i<4; i++)
    {
        vehicles[i]->details();
    }

    return 0;
}
