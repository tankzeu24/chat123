#ifndef ELECTRICDEVICE_H
#define ELECTRICDEVICE_H
#include <iostream>
using namespace std;


class ElectricDevice
{
    public:
        ElectricDevice();
        virtual ~ElectricDevice();
        ElectricDevice(const char* name, int consumedPower);
        ElectricDevice(const ElectricDevice &electricDevice);
        ElectricDevice& operator=(const ElectricDevice &electricDevice);

        char* getName() const;
         int getConsumedPower() const;
        void setName(const char* toCopyName);
        void setConsumedPower(int toCopyConsumedPower);
        friend ostream& operator<<(ostream &os ,const ElectricDevice &electricDevice);
        bool operator==(const ElectricDevice &electricDevice);
        bool operator!=(const ElectricDevice &electricDevice);



    protected:

    private:

         void copyName(const char* name);
        char* name;
         int consumedPower;
};

#endif // ELECTRICDEVICE_H
