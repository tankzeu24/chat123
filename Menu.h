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
    void chooseOptionFromMenu()  const ;


    void listCustomers()  const ;
    void addNewCustomer();
    void deleteCustomer();
    void listAllAccounts() const ;
    void listCustomerAccounts() const ;
    void addnewAccount();
    void deleteAccount();
    void withdrawFromAccount();
    void depositToAccount();
    void tansfer();
    void DisplayInfoForTheBank() const ;

    Bank getBank() const;
protected:

private:
    Bank bank;
};

#endif // MENU_H
