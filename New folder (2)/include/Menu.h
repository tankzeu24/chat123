#ifndef MENU_H
#define MENU_H
#include "Store.h"

class Menu
{
    public:
        Menu(const Store& store);
        virtual ~Menu();

    void start();
    void display() const;
    private:
        Store store;
};

#endif // MENU_H
