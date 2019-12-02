#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Account.h"
#include "Customer.h"

using namespace std;
struct {
  bool operator()(Customer& c1, Customer& c2){
    if (c1.getFirstName() != c2.getFirstName()){
        return c1.getFirstName() < c2.getFirstName();
    }
    else {return c1.getLastName() < c2.getLastName();}
    }
} alfabetikus;
int main()
{
    Account a(500);
    /*cout << a.getBalance() << endl;
    a.deposit(500); cout << a.getBalance() << endl;
    a.withdraw(1000); cout << a.getBalance() << endl;*/

    Customer c1 ("Anna", "Benedek"); c1.addAccount(a);
    Account a1(3000), a2; Customer c2 ("Istvan", "Benedek"); c2.addAccount(a1); c2.addAccount(a2);
    //cout << c1 << c2;

    try {
        Account a3 = c1.getAccount(3);
    } catch (out_of_range& e){
        cout << e.what() << endl;
    }

    Customer c3 ("Anna", "Kovacs");
    Account a3(0); c3.addAccount(a3);

    vector<Customer> v;
    cout << endl << "Rendezes elott: " << endl;

    v.push_back(c1); v.push_back(c2); v.push_back(c3);
    for (unsigned int i = 0; i < v.size(); ++i){
        cout << v[i];
    }

    cout << endl << "Rendezes utan: " << endl;

    sort(v.begin(),v.end());
    for (unsigned int i = 0; i < v.size(); ++i){
        cout << v[i];
    }

    cout << endl << "Nevsor szerint: " << endl;
    sort(v.begin(),v.end(),alfabetikus);
    for (unsigned int i = 0; i < v.size(); ++i){
        cout << v[i];
    }

    return 0;
}
