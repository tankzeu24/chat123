#ifndef MENU_H
#define MENU_H
#include "Bank.h"

class Menu
{
public:
    Menu();
    Menu(const Bank &bank);
    Menu& operator=(const Menu &bank);
    virtual ~Menu();

    void start() ;

    void displayMainMenu() const ;


//since menu's serves as UI let this be it's only option
// everything else should be hidden
private:
    void chooseOption();
    void listCustomers() const;
    void addNewCustomer();
    void deleteCustomer();
    void listAllAccounts() const;
    void listCustomerAccounts() const;
    void addnewAccount();
    void deleteAccount();
    void withdrawFromAccount();
    void depositToAccount();
    void tansfer();
    void displayInfoForTheBank() const;
    Bank getBank() const;




    Bank bank;
};

#endif // MENU_H
