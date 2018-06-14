#include "Store.h"
#include "Product.h"

int Store::counter=0; //generates unique SKU's

Store::Store()
{

    maxSize = 5;
    currentSize = 0;
    list = new Product[maxSize];
}

Store::~Store()
{
    delete[] list;
}
Store::Store(const Store& store)
{
    maxSize=store.getMaxSize();
    currentSize=store.getCurrentSize();
    list=new Product[maxSize];
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
        list=new Product[maxSize];
        for(int i=0; i<currentSize; i++)
        {
            list[i]=store.getElement(i);
        }
    }
    return *this;
}
Product Store::getElement(int pos) const
{
    if( pos<0 || pos>currentSize)
    {
        throw std::out_of_range("out of range position");
    }
    Product product(list[pos]);
    return product;
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
        grow();
    }

    cin >> list[currentSize];

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
    int productSKU = findProduct(SKU);

    if (productSKU == -1)
    {
        throw std::invalid_argument(" Product not found in product list");
    }
    else
    {
        for (int j = productSKU + 1; j < currentSize; j++)
            list[j - 1] = list[j];

        currentSize--;
        for(int i=0; i<currentSize; i++)
        {
            list[i].setCount(currentSize);
        }

        cout << "Product removed.\n";
    }
}

void Store::update()
{
    int findSKU;
    cout<<"Enter SKU"<<endl;
    cin>>findSKU;

    int newSKU=findProduct(findSKU);
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
        cin.ignore();
        char brand[50];
        cin.getline(brand,50);
        list[newSKU].setBrand(brand);
        break;
    case 4:
        cin.ignore();
        char model[50];
        cin.getline(model,50);
        list[newSKU].setModel(model);
        break;
    case 5:
        cin.ignore();
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
        cout << "\nCurrent Store  is empty.\n";

    }
    else
    {
        cout<<"Current number of elements : "<<currentSize<<" " <<"Capacity is "<<maxSize<<endl;
        for (int i = 0; i < currentSize; i++)
        {
            cout << list[i];
        }

    }

}

void Store::grow()
{
    maxSize = currentSize + 5;
    Product* newList = new Product[maxSize];

    for (int i = 0; i < currentSize; i++)
        newList[i] = list[i];

    delete[] list;
    list = newList;
}

int Store::findProduct(int SKU) const
{
    if (SKU < 1 || SKU > counter)
    {
        throw std::out_of_range("SKU does not exist");
    }
    for(int i=0; i<currentSize; i++)
    {
        if(list[i].getSKU()==SKU)
        {
            return i;
        }
    }

    return -1;

}
