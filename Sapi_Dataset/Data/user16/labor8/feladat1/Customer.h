#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"

using namespace std;


class Customer
{
    public:
        Customer(string firstName , string lastName);
        int getNumOfAccounts () const;
        Account & getAccount (int index);
        void addAccount (Account account);
        friend ostream & operator<<(ostream & os, const Customer & customer);
        string getFirstName () const;
        string getLastName () const;
        friend bool operator<(const Customer & a , const Customer & b);

    private:
        string firstName , lastName;
        vector <Account> accounts;
};

#endif // CUSTOMER_H
