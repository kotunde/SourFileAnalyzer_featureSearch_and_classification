#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Account.h"
#include "Customer.h"

bool cmp (const Customer & a, const Customer & b)
{
    return (a<b);
}

struct myclass
{
    int operator()(const Customer & a, const Customer & b)
    {
        if (a.getFirstName() == b.getFirstName())
            return (a.getLastName() < b.getLastName());
        return (a.getFirstName() < b.getFirstName());
    }
} myobject;

using namespace std;

int main()
{
    /* Account p (1000);
     p.deposit(100);
     cout<<p.getBalance()<<endl;
     p.withdraw(500);
     cout<<p.getBalance();
    */
    Customer a("Nagy","Lajos");
    a.addAccount(Account(3000));
    a.addAccount(Account(1000));
    cout<<a;
    Customer b("Fazakas","Eszter");
    b.addAccount(Account(1500));
    b.addAccount(Account(1500));
    Customer c ("Fazakas","Szilard");
    c.addAccount(Account(10000));

    cout<<b;
    cout<<endl<<(a<b)<<endl;


    vector <Customer> t;
    t.push_back(c);
    t.push_back(a);
    t.push_back(b);

    sort(t.begin(),t.end(),cmp);
    cout<<"\n\nrendezve penz szerint : "<<endl<<endl;
    for (int i = 0 ; i<t.size(); i++)
    {
        cout<<t[i];
    }

    cout<<endl<<endl;
    sort(t.begin(),t.end(),myobject);
    cout<<"\n\Alfabetikus sorrendbe rendezve : "<<endl<<endl;
    for (int i = 0 ; i<t.size(); i++)
    {
        cout<<t[i];
    }


}
