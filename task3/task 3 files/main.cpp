#include <iostream>

using namespace std;
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"
int main()
{
   Car c;
   c.details(); //shows default values

   Car c1=Car("Porche","Best","Red",2000,100);
   c1.details(); //shows the details

   Truck t=Truck("KMZ","Top","Blue",1990,50,200);
   t.details();

   Motorcycle m=Motorcycle("Raider","nice","Green",2001,20,"Chopper");
   m.details();


    return 0;
}
