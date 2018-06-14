#ifndef INTERACTIVEMENU_H
#define INTERACTIVEMENU_H
#include "Store.h"

class InteractiveMenu
{
public:
    InteractiveMenu(const Store& store);
    InteractiveMenu& operator=(const Store& store) =delete;
    InteractiveMenu& operator=(const InteractiveMenu& interactiveMenu) =delete;
    virtual ~InteractiveMenu();

    void start();
    void display() const;
    void chooseOption();
private:
    Store store;
};

#endif // INTERACTIVEMENU_H
