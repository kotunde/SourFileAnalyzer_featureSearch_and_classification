#include "Person.h"
#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
using namespace std;
struct PersonCompare
{
    bool operator()(const Person & p1,const Person& p2)
    {
        if (p1.getFirstName()<p2.getFirstName())
        {
            return true;
        }
        if(p1.getFirstName()==p2.getFirstName())
        {
            return p1.getLastName()<p2.getLastName();
        }
        return false;
    }
} ;

int main()
{
    set<Person,PersonCompare> p;
    Person p1("Fekete","Timi");
    Person p2("Kiss","Janos");
    Person p3("Kiss","Ibolya");
    p.insert(p1);
    p.insert(p2);
    p.insert(p3);
    for(auto& x:p)
    {
        cout<<x;
    }
    cout<<"lambda:"<<endl;
    auto comp = [](Person x, Person y)
    {
         if (x.getFirstName()<y.getFirstName())
        {
            return true;
        }
        if(x.getFirstName()==y.getFirstName())
        {
            return x.getLastName()<y.getLastName();
        }
        return false;
    };
    set<Person,decltype(comp)> s(comp);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    for(auto& x:p)
    {
        cout<<x;
    }
    return 0;
}
