#include <iostream>

using namespace std;
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"
int main()
{
    Car c;
    cout<<"Default car : "<<endl;
    c.details(); //shows default values

    Car c1=Car("Porche","Best","Red",2000,100);
    c1.details(); //shows the details

    Truck t=Truck("KMZ","Top","Blue",1990,50,200);
    t.details();

    Motorcycle m=Motorcycle("Raider","nice","Green",2001,20,"touring");
    m.details();

    cout<<"=========="<<endl;
    cout<<"Example using virtual function : "<<endl;
    Vehicle* vehicles[]= {&c,&c1,&t,&m};
    for(int i=0; i<4; i++)
    {
        vehicles[i]->details();
    }

    return 0;
}
