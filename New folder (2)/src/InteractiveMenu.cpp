#include "InteractiveMenu.h"
#include "Store.h"

InteractiveMenu::InteractiveMenu(const Store &newStore)
{
    store=newStore;
}

InteractiveMenu::~InteractiveMenu()
{
    //dtor
}

void InteractiveMenu::displayProperties() const
{
    cout<<"Choose property"<<endl;
    cout<<"1 Brand"<<endl;
    cout<<"2 Model"<<endl;
    cout<<"3 Category"<<endl;
    cout<<"4 Price"<<endl;
    cout<<"5 Mileage"<<endl;
}

void InteractiveMenu::display() const
{
    cout<<"Enter option"<<endl;
    cout<<"A Add new product"<<endl;
    cout<<"X Delete product"<<endl;
    cout<<"C Change product"<<endl;
    cout<<"D Display products"<<endl;
    cout<<"Q Quit"<<endl;
}

void InteractiveMenu::start()

{
    while(true)
    {

        display();
        char choice;
        cin>>choice;




        switch(choice)
        {
        case 'A':

            store.insert();
            cin.ignore();

            break;

        case 'X':
            int id;
            cout<<"Enter id"<<endl;
            cin>>id;
            store.remove(id);
            break;
        case 'C':
            displayProperties();
            store.update();
            break;
        case 'D':
            store.display();

            break;

        case 'Q':
            break;
            exit(0);
        default:
            cout<<"Wrong option,try again!"<<endl;
        }
        cin.ignore();


    }
}
