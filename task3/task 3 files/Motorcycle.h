#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"
#include "cstring"
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
    bool validateType(const char* newType);
    enum {CONSTANTS_SIZE=4};
    const char* typeConstants[CONSTANTS_SIZE] = { "chopper", "cruiser", "dirt bike", "touring" };
    char* type;
};

#endif // MOTORCYCLE_H
