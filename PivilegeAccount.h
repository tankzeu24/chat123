#ifndef PIVILEGEACCOUNT_H
#define PIVILEGEACCOUNT_H

#include "Account.h"


class PivilegeAccount :public Account
{
public:
    PivilegeAccount();
    PivilegeAccount(int newIban,int newOwner,double newAmount,double newOverdraft);
    PivilegeAccount(const PivilegeAccount& privilegeAccount);
    PivilegeAccount& operator=(const PivilegeAccount &privilegeAccount);
    virtual ~PivilegeAccount();

    void setOverdraft(double newOverdraft);
    double getOverdraft() const;

    void deposit(double sum);
    bool withdraw(double sum);
    void display() const;
protected:

private:
    double overdraft;
};

#endif // PIVILEGEACCOUNT_H
