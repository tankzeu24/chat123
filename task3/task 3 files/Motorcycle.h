#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
    public:
        Motorcycle();
        virtual ~Motorcycle();
        Motorcycle(const char* make,const char* model,const char* color,int year,int mileage,const char* type);
        Motorcycle(const Motorcycle &motorcycle);
        Motorcycle& operator=(const Motorcycle &motorcycle);
        void details() const;
        void setType(const char* s);
        char* getType() const;
    protected:

    private:


        char* type;
};

#endif // MOTORCYCLE_H
