#ifndef INTERACTIVEMENU_H
#define INTERACTIVEMENU_H
#include "Store.h"

class InteractiveMenu
{
  public:
        InteractiveMenu(const Store& store);
        virtual ~InteractiveMenu();

    void start();
    void display() const;
    void displayProperties() const;
    private:
        Store store;
};

#endif // INTERACTIVEMENU_H
