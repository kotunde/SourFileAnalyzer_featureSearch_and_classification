#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account(double balance = 1000);
    double getBalance () const;
    void deposit (double amount);
    bool withdraw (double amount);
private :
    double balance;
};

#endif // ACCOUNT_H
