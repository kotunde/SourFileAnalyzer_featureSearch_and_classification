#include "Account.h"

Account::Account(double balance)
{
    this->balance = balance;
}

double Account :: getBalance () const
{
    return this->balance;
}

void  Account :: deposit (double amount)
{
    this->balance+=amount;
}

bool Account :: withdraw (double amount)
{
    if (this->balance>=amount)
    {
        this->balance-=amount;
        return true;
    }
    return false;
}

