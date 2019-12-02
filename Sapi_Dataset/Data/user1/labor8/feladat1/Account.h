#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

class Account {
public:
    Account(double balance = 1000);
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
private:
    double balance;
};


#endif // ACCOUNT_H_INCLUDED
