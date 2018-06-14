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



void InteractiveMenu::display() const
{
    cout<<"Enter option"<<endl;
    cout<<"A Add new product"<<endl;
    cout<<"X Delete product"<<endl;
    cout<<"C Change product"<<endl;
    cout<<"D Display products"<<endl;
    cout<<"Q Quit"<<endl;
}

void InteractiveMenu::chooseOption()
{
    char choice;
    cin>>choice;




    switch(choice)
    {
    case 'A':

        store.insert();
        break;

    case 'X':
        int id;
        cout<<"Enter SKU"<<endl;
        cin>>id;
        store.remove(id);
        break;
    case 'C':
        store.update();
        break;
    case 'D':
        store.display();
        break;

    case 'Q':
        exit(0);
    default:
        cout<<"Wrong option,try again!"<<endl;
    }


}

void InteractiveMenu::start()

{
    while(true)
    {

        display();
        cout<<endl;
        try
        {
            chooseOption();

        }
        catch (const std::invalid_argument &e)
        {
            cout<<e.what()<<endl;
        }
        catch( const  std::out_of_range &e1)
        {
            cout<<"Out of range error found"<<endl;
            cout<<e1.what();
            cout<<endl;
        }



    }
}
