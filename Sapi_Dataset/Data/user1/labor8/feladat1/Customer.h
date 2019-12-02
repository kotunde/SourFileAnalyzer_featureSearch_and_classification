#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <string>
#include "Account.h"
#include <vector>

using namespace std;

class Customer {
public:
    Customer (string firstName, string lastName);
    int getNumOfAccounts() const;
    Account& getAccount (int index);
    void addAccount (Account account);
    friend ostream& operator<< (ostream& os, Customer& customer);
    string getFirstName() const;
    string getLastName() const;
    friend bool operator< (Customer& c1, Customer& c2);
private:
    string firstName, lastName;
    vector<Account> accounts;
};
#endif // CUSTOMER_H_INCLUDED
