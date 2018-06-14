#include <iostream>
using namespace std;
#include "Store.h"
#include "InteractiveMenu.h"


int main()
{

    Store s =Store();
    InteractiveMenu menu =InteractiveMenu(s);
    menu.start();

    return 0;
}
