#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car: public Vehicle
{
    public:
        Car();
        Car(const char* make,const char* model,const char* color,int year,int mileage);
        Car(const Car &car);
        Car& operator=(const Car& car);
        virtual ~Car();
        void details() const;

    protected:

    private:
};

#endif // CAR_H
