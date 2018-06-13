#include "MainMenu.h"
#include "Store.h"

MainMenu::MainMenu(const Store &newStore)
{
    store=newStore;
}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::display() const
{
    cout<<"Choose property"<<endl;
    cout<<"1 Brand"<<endl;
    cout<<"2 Model"<<endl;
    cout<<"3 Category"<<endl;
    cout<<"4 Price"<<endl;
    cout<<"5 Mileage"<<endl;
}

void MainMenu::start()

{
    while(true)
    {

        display();
        char choice;

        while(choice != 'A' || choice != 'X' || choice !='C' || choice != 'D' || choice != 'Q')
        {
            cout<<"Enter valid option from the menu"<<endl;
        }
        switch(choice)
        {
        case 'A':
            store.insert();
            break;

        case 'X':
            store.remove();
            break;
        case 'C':
            store.update();
            break;
        case 'D':
            store.display();
            break;
        case 'Q':
            break;
            exit(0);
        }


    }
}
