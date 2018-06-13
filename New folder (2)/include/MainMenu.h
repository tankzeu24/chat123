#ifndef MAINMENU_H
#define MAINMENU_H
#include "Store.h"

class MainMenu
{
  public:
        MainMenu(const Store& store);
        virtual ~MainMenu();

    void start();
    void display() const;
    private:
        Store store;
};

#endif // MAINMENU_H
