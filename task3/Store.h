#ifndef STORE_H
#define STORE_H
#include "Product.h"

class Store
{
public:
    Store();
    Store(const Store &store);
    Store& operator=(const Store &store);
    ~Store();

    void insert();
    void lookup() const;
    void remove(int id);
    void update();
    void display() const;

    int getMaxSize() const;
    int getCurrentSize() const;
    Product getElement(int pos) const;
private:
    static int counter;
    int	maxSize,
        currentSize;
    Product* list;
    void grow();
    int findProduct(int id) const;
};



#endif // STORE_H
