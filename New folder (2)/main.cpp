#include <iostream>
using namespace std;
#include "Store.h"
#include "InteractiveMenu.h"


int main()
{

    Store s =Store();
    InteractiveMenu menu =InteractiveMenu(s);
    menu.start();


    while(true)
    {

        menu.display();
        char choice;
        cin>>choice;

        switch(choice)
        {
        case 'A':
            Car c;

            cin>>c;
            cin.ignore();

            break;
        }
       cin.ignore();

    }


    return 0;
}
