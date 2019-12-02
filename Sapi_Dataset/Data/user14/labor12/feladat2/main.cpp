#include <iostream>
#include <set>
#include "Person.h"

///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///FUggvenyobjektum + Lamba kifejezes
using namespace std;



struct PersonCompare
{
    bool operator()(const Person p1, const Person p2)
    {
        if (p1.getFirstName()==p2.getFirstName())
        {
            return p1.getLastName()<p2.getLastName();
        }
        return p1.getFirstName()<p2.getFirstName();
    }
};


int main()
{
    auto comp = [](Person p1, Person p2) {if (p1.getFirstName()==p2.getFirstName())
                                            {
                                                return p1.getLastName()<p2.getLastName();
                                            }
                                                return p1.getFirstName()<p2.getFirstName();};
    //set<Person, decltype(comp)> s(comp);
    set <Person,PersonCompare> s;
    Person sz1("Kovacs","Bela");
    s.insert(sz1);
    Person sz2("Hegyi","Janos");
    s.insert(sz2);
    Person sz3("Tar","Istvan");
    s.insert(sz3);
    Person sz4("Antal","Janos");
    s.insert(sz4);
    for (auto& x: s)
    {
        cout << x ;
    }
    cout << endl;
    return 0;
}
