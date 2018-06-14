#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

//The product defined is a car
//the car has Brand ,Model,Category ,price,miles ran
class Product
{
public:
    Product(int newSKU=1,int newCount=1,const char* newBrand="BMV",const char* newModel="Q8",const char* newCategory="Sedan",double newPrice=30000.0,int newMiles=1.0);
    Product(const Product &product);
    Product& operator=(const Product &product);
    virtual ~Product();


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

    friend ostream& operator<<(ostream &os,const Product &product);
    friend istream& operator>>(istream &is,Product &product);


private:
    int SKU;
    int Count;
    char* Brand;  //brand of the car
    char* Model;    // model of the car
    char* Category; // category to it belongs
    double Price;  //price of the car
    int Miles; //total miles ran by the car
    void setStringProperty(char *&prop, const char *toCopyString);
};

#endif // PRODUCT_H
