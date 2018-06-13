#include "Car.h"
#include <cstring>
#include <iostream>
using namespace std;



Car::Car(int newSKU,int newCount,const char* newBrand,const char* newModel,const char* newCategory,double newPrice,int newMiles):Brand(nullptr),Model(nullptr),Category(nullptr)
{

    setSKU(newSKU);
    setCount(newCount);
    setModel(newModel);
    setCategory(newCategory);
    setPrice(newPrice);
    setMiles(newMiles);
}

Car::Car(const Car &car):Brand(nullptr),Model(nullptr),Category(nullptr)
{
    setSKU(car.getSKU());
    setCount(car.getCount());
    setBrand(car.getBrand());
    setModel(car.getModel());
    setCategory(car.getCategory());
    setPrice(car.getPrice());
    setMiles(car.getMiles());
}

Car& Car::operator=(const Car &car)
{
    if(this != &car)
    {
     setSKU(car.getSKU());
    setCount(car.getCount());
        setBrand(car.getBrand());
    setModel(car.getModel());
    setCategory(car.getCategory());
    setPrice(car.getPrice());
    setMiles(car.getMiles());
    }
    return *this;
}

Car::~Car()
{
   delete[] Brand;
   delete[] Model;
   delete[] Category;
}

void Car::setSKU(int newSKU)
{
    if(newSKU<1)
    {
        throw std::invalid_argument("SKU cannot be < 1");
    }
    SKU=newSKU;
}

void Car::setCount(int newCount)
{
    if(newCount<1)
    {
        throw std::invalid_argument("Count cannot be < 0");
    }
    Count=newCount;
}



void Car::setBrand(const char* newBrand)
{
    setStringProperty(Brand,newBrand);
}

void Car::setCategory(const char* newCategory)
{
    setStringProperty(Category,newCategory);
}

void Car::setModel(const char* newModel)
{
    setStringProperty(Model,newModel);
}

void Car::setPrice(double newPrice)
{
    if(newPrice<=0)
    {
        throw std::invalid_argument("price cannot be <=0");
    }
    Price=newPrice;
}

void Car::setMiles(int newMiles)
{
    if(newMiles<=0)
    {
        throw std::invalid_argument("newMiles cannot be <=0");
    }
    Miles=newMiles;
}

int Car::getSKU() const
{
    return SKU;
}

int Car::getCount() const
{
    return Count;
}
char* Car::getBrand() const
{
    return Brand;
}

char* Car::getCategory() const
{
    return Category;
}

char* Car::getModel() const
{
    return Model;
}

double Car::getPrice() const
{
    return Price;
}

int Car::getMiles() const
{
    return Miles;

}

 ostream& operator<<(ostream &os , const Car &car)
{   os<<"SKU : "<<car.getSKU()<<" "<<car.getCount()<<endl;
    os<<"Model : " <<car.getModel()<<" Brand: "<<car.getBrand()<< " Category: "<<car.getCategory()<<" ";
    os<<"Price :"<<car.getPrice()<<" Miles: "<<car.getMiles()<<endl;
    return os;
}
istream& operator>>(istream &is , Car &car)

{

cout<<"Enter price"<<endl;

double price;

is>>price;

car.setPrice(price);

cout<<"Enter miles"<<endl;

int miles;

is>>miles;

car.setMiles(miles);

cout<<"Enter brand"<<endl;

char brand[50];

is.getline(brand,50);

is.ignore();

car.setBrand(brand);

cout<<"Enter model"<<endl;

char model[50];

is.getline(model,50);

is.ignore();

car.setModel(model);

cout<<"Enter category"<<endl;

char category[50];

is.getline(category,50);

is.ignore();

car.setCategory(category);

return is;

}

bool Car::operator==(const Car &car)
{
    int firstCondition=strcmp(getBrand(),car.getBrand());
    int secondCondition=strcmp(getModel(),car.getModel());
    int thirdCondition=strcmp(getCategory(),car.getCategory());
    if( getSKU()==car.getSKU()
       && firstCondition && secondCondition
       && thirdCondition
       && car.getPrice()==getPrice()
       && car.getMiles()==car.getMiles()
       )
    {
        return true;
    }
    return false;
}

bool Car::operator!=(const Car &car)
{
    return !(*this==car);
}

void Car::setStringProperty(char *&prop, const char *toCopyString)
{
    if(toCopyString != NULL)
    {
        delete[] prop;
        prop = new char[strlen(toCopyString)+1];
        strcpy(prop, toCopyString);
    }
}
