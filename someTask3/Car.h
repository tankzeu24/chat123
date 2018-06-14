#ifndef CAR_H
#define CAR_H
#include<iostream>
using namespace std;

class Car
{
public:
    Car(int newSKU=1,int newCount=1 ,const char* newBrand="BMV",const char* newModel="Q8",const char* newCategory="Sedan",double newPrice=30000.0,int newMiles=1.0);
    Car(const Car &car);
    Car& operator=(const Car &car);
    virtual ~Car();


    int getSKU() const;
    char* getBrand() const;
    char* getModel() const;
    char* getCategory() const;
    double getPrice() const;
    int getMiles() const;
    int getCount() const;


    void setSKU(int newSKU);
    void setBrand(const char* newBrand);
    void setModel(const char* newModel);
    void setCategory(const char* newCategory);
    void setPrice(double newPrice);
    void setMiles(int newMiles);
    void setCount(int newCount);

    friend ostream& operator<<(ostream &os,const Car &car);
    friend istream& operator>>(istream &is,Car &car);
    bool operator==(const Car &car);
    bool operator!=(const Car &car);
protected:

private:
    static int carCounter;
    int SKU;
    int Count;
    char* Brand;
    char* Model;
    char* Category; //Truck,sedan etc.
    double Price;
    int Miles; //total miles ran by the car
    void setStringProperty(char *&prop, const char *toCopyString);
};


#endif // CAR_H


