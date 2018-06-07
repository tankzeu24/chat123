#include <iostream>
using namespace std;
#include "CurrentAccount.h"
#include "PivilegeAccount.h"
#include <set>
#include "Bank.h"
#include "Menu.h"



int main()
{
    Bank bank ("BNB bank","Main street 34");
    Menu menu(bank);
    menu.start();


    return 0;
}
