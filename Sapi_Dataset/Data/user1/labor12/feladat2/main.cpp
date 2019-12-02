#include <iostream>
#include <set>
#include "Person.h"

using namespace std;

struct PersonCompare{
    bool operator()(const Person& p1, const Person& p2) const{
        return p1.getFirstName() < p2.getFirstName();
    }
};

int main()
{
    set<Person,PersonCompare> s1;
    Person p1("Kovacs","Anna");
    s1.insert(p1);
    Person p2("Balazs","Laszlo");
    s1.insert(p2);
    Person p3("Szabo","Katalin");
    s1.insert(p3);

    for (auto& x: s1 ){
        cout << x;
    }
    cout << endl;

    //lambda
    auto comp = [](Person p1, Person p2){
        return p1.getFirstName() < p2.getFirstName();};

    set<Person,decltype(comp)> s2(comp);
    s2.insert(p1); s2.insert(p2); s2.insert(p3);
    for (auto& x: s2 ){
        cout << x;
    }

    return 0;
}
