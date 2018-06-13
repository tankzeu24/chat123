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
    maxSize=store.getCurrentSize();
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
        maxSize=store.getCurrentSize();
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
    if (currentSize == maxSize)		// ако списъкът е пълен, тогава извикай grow
        grow();



    cin >> list[currentSize++];	// прочита нов контакт

    counter++;
    list[currentSize].setSKU(counter);
    list[currentSize].setCount(counter);
}



void Store::remove(int SKU)
{
    // Prompt the user for the name to be removed.


    int thisCar = findCar(SKU);

    if (thisCar == -1)
        cout <<" Car not found in car list";
    else
    {
        for (int j = thisCar + 1; j < currentSize; j++)
            list[j - 1] = list[j];

        currentSize--;
        for(int i=0; i<currentSize; i++)
        {
            list[i].setCount(counter-1);
        }

        cout << "Car removed.\n";
    }
}

void Store::update()
{
    int findSKU;
    cin>>findSKU;
    while (findSKU < 1 || findSKU > currentSize)
    {
        cout<<"enter valid SKU please"<<endl;
    }
    cout<<"Choose property"<<endl;
    cout<<"1 Brand"<<endl;
    cout<<"2 Model"<<endl;
    cout<<"3 Category"<<endl;
    cout<<"4 Price"<<endl;
    cout<<"5 Mileage"<<endl;
    int propertyChoice;
    cin>>propertyChoice;
    switch(propertyChoice)
    {
    case 1:
        char brand[50];
        cin.getline(brand,50);
        list[findSKU].setBrand(brand);
    case 2:
        char model[50];
        cin.getline(model,50);
        list[findSKU].setModel(model);
    case 3:
        char category[50];
        cin.getline(category,50);
        list[findSKU].setCategory(category);
    case 4:
        double price;
        cin>>price;
        list[findSKU].setPrice(price);
    case 5:
        int mileage;
        cin>>mileage;
        list[findSKU].setMiles(mileage);
    }


}

void Store::display() const
{
    if (currentSize == 0)
    {
        cout << "\nCurrent contact list is empty.\n";
        return;
    }


    for (int i = 0; i < currentSize; i++)
        cout << list[i];
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
