#include "Store.h"
#include "Car.h"

int Store::counter=0;

Store::Store()
{

    maxSize = 5;
    currentSize = 0;
    list = new Car[maxSize];
}

Store::~Store()
{
    delete[] list;
}
Store::Store(const Store& store)
{
    maxSize=store.getMaxSize();
    currentSize=store.getCurrentSize();
    list=new Car[maxSize];
    for(int i=0; i<currentSize; i++)
    {
        list[i]=store.getElement(i);
    }

}

Store& Store::operator=(const Store &store)
{
    if(this != &store)
    {
        maxSize=store.getMaxSize();
        currentSize=store.getCurrentSize();
        delete[] list;
        list=new Car[maxSize];
        for(int i=0; i<currentSize; i++)
        {
            list[i]=store.getElement(i);
        }
    }
    return *this;
}
Car Store::getElement(int pos) const
{
    if( pos<0 || pos>currentSize)
    {
        throw std::invalid_argument("out of range position");
    }
    Car car(list[pos]);
    return car;
}
int Store::getCurrentSize() const
{
    return currentSize;
}

int Store::getMaxSize() const
{
    return maxSize;
}
void Store::insert()
{

    if (currentSize == maxSize)
    {
        cout<<currentSize<<" " <<maxSize<<endl;
        grow();
        cout<<"LETS GROW"<<endl;
    }// ако списъкът е пълен, тогава извикай grow




    cin >> list[currentSize];	// прочита нов контакт

    counter++;
    list[currentSize].setSKU(counter);
    for(int i=0; i<=currentSize; i++)
    {
        list[i].setCount(currentSize+1);
    }

    currentSize++;

}



void Store::remove(int SKU)
{
    // Prompt the user for the name to be removed.


    int thisCar = findCar(SKU);

    if (thisCar == -1)
    {
        throw std::invalid_argument(" Car not found in car list");
    }
    else
    {
        for (int j = thisCar + 1; j < currentSize; j++)
            list[j - 1] = list[j];

        currentSize--;
        for(int i=0; i<currentSize; i++)
        {
            list[i].setCount(currentSize);
        }

        cout << "Car removed.\n";
    }
}

void Store::update()
{
    int findSKU;
    cout<<"Enter SKU"<<endl;
    cin>>findSKU;

        int newSKU=findCar(findSKU);
        if (newSKU==-1)
        {
            throw std::invalid_argument("SKU does not exist in the store");
        }


    cout<<"Choose property"<<endl;
    cout<<"1 Price"<<endl;
    cout<<"2 Mileage"<<endl;
    cout<<"3 Brand"<<endl;
    cout<<"4 Model"<<endl;
    cout<<"5 Category"<<endl;

    int propertyChoice;
    cin>>propertyChoice;

    switch(propertyChoice)
    {

    case 1:
        cout<<"enter price"<<endl;
        cout<<list[newSKU]<<endl;
        double price;
        cin>>price;

        list[newSKU].setPrice(price);
        break;
    case 2:
        int mileage;
        cin>>mileage;

        list[newSKU].setMiles(mileage);
        break;
    case 3:
        char brand[50];
        cin.getline(brand,50);
        list[newSKU].setBrand(brand);
        break;
    case 4:
        char model[50];
        cin.getline(model,50);
        list[newSKU].setModel(model);
        break;
    case 5:
        char category[50];
        cin.getline(category,50);
        list[newSKU].setCategory(category);
        break;
    }


}

void Store::display() const
{
    if (currentSize == 0)
    {
        cout << "\nCurrent contact list is empty.\n";

    }
    else
    {
        cout<<"currentSize is : "<<currentSize<<" " <<"maxSize is "<<maxSize<<endl;
        for (int i = 0; i < currentSize; i++)
            cout << list[i];
    }

}

void Store::grow()
{
    maxSize = currentSize + 5;				// определяне на новия размер.
    Car* newList = new Car[maxSize];		// алокиране на нов масив.

    for (int i = 0; i < currentSize; i++)	// копиране в новия масив
        newList[i] = list[i];

    delete[] list;
    list = newList;
}

int Store::findCar(int SKU) const
{
    if (SKU < 1 || SKU > currentSize)
    {
        throw std::invalid_argument("SKU does not exist");
    }
    for(int i=0; i<currentSize; i++)
    {
        if(list[i].getSKU()==SKU)
        {
            return i;
        }
    }

    return -1;
    /*
    for (int i = 0; i < currentSize; i++)
    	if (strcmp(list[i].getName(), aName) == 0)
    		return i;		// return i ако е намерено

    return -1;				// return -1 ако не е намерено
    */
}
