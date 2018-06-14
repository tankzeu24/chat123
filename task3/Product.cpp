#include "Product.h"

#include <cstring>
#include <iostream>
using namespace std;

//The product defined is a car
//the car has Brand ,Model,Category ,price,miles ran

Product::Product(int newSKU,int newCount,const char* newBrand,const char* newModel,const char* newCategory,double newPrice,int newMiles):Brand(nullptr),Model(nullptr),Category(nullptr)
{

    setSKU(newSKU);
    setCount(newCount);
    setModel(newModel);
    setCategory(newCategory);
    setPrice(newPrice);
    setMiles(newMiles);
}

Product::Product(const Product &product):Brand(nullptr),Model(nullptr),Category(nullptr)
{
    setSKU(product.getSKU());
    setCount(product.getCount());
    setBrand(product.getBrand());
    setModel(product.getModel());
    setCategory(product.getCategory());
    setPrice(product.getPrice());
    setMiles(product.getMiles());
}

Product& Product::operator=(const Product &product)
{
    if(this != &product)
    {
        setSKU(product.getSKU());
        setCount(product.getCount());
        setBrand(product.getBrand());
        setModel(product.getModel());
        setCategory(product.getCategory());
        setPrice(product.getPrice());
        setMiles(product.getMiles());
    }
    return *this;
}

Product::~Product()
{
    delete[] Brand;
    delete[] Model;
    delete[] Category;
}

void Product::setSKU(int newSKU)
{
    if(newSKU<0)
    {
        throw std::invalid_argument("SKU cannot be < 1");
    }

    SKU=newSKU;
}

void Product::setCount(int newCount)
{
    if(newCount<0)
    {
        throw std::invalid_argument("Count cannot be < 0");
    }

    Count=newCount;
}



void Product::setBrand(const char* newBrand)
{
    setStringProperty(Brand,newBrand);
}

void Product::setCategory(const char* newCategory)
{
    setStringProperty(Category,newCategory);
}

void Product::setModel(const char* newModel)
{
    setStringProperty(Model,newModel);
}

void Product::setPrice(double newPrice) //price cannot be negative
{
    if(newPrice<=0)
    {
        throw std::invalid_argument("price cannot be <=0");
    }
    Price=newPrice;
}

void Product::setMiles(int newMiles) //it has run at least something
{
    if(newMiles<=0)
    {
        throw std::invalid_argument("newMiles cannot be <=0");
    }
    Miles=newMiles;
}

int Product::getSKU() const
{
    return SKU;
}

int Product::getCount() const
{
    return Count;
}
char* Product::getBrand() const
{
    return Brand;
}

char* Product::getCategory() const
{
    return Category;
}

char* Product::getModel() const
{
    return Model;
}

double Product::getPrice() const
{
    return Price;
}

int Product::getMiles() const
{
    return Miles;

}

ostream& operator<<(ostream &os, const Product &product)
{

    os<<"SKU : "<<product.getSKU()<<" ,Count : "<<product.getCount()<<" ,Model : " <<product.getModel()
      <<" ,Brand : "<<product.getBrand()<< " ,Category : "<<product.getCategory()
      <<" ,Price : "<<product.getPrice()<<" ,Miles : "<<product.getMiles()<<endl;
    return os;
}
istream& operator>>(istream &is, Product &product)

{

    cout<<"Enter price"<<endl;
    double price;
    is>>price;
    product.setPrice(price);
    is.ignore();

    cout<<"Enter miles"<<endl;
    int miles;
    is>>miles;
    product.setMiles(miles);
    is.ignore();

    cout<<"Enter brand"<<endl;
    char brand[50];
    is.getline(brand,50);
    product.setBrand(brand);

    cout<<"Enter model"<<endl;
    char model[50];
    is.getline(model,50);
    product.setModel(model);

    cout<<"Enter category"<<endl;
    char category[50];
    is.getline(category,50);
    product.setCategory(category);

    return is;

}



void Product::setStringProperty(char *&prop, const char *toCopyString)
{
    if(toCopyString != NULL)
    {
        delete[] prop;
        prop = new char[strlen(toCopyString)+1];
        strcpy(prop, toCopyString);
    }
}
