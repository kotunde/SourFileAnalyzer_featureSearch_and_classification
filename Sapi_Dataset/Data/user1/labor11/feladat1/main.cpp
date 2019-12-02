#include <iostream>
#include "OrderedList.h"
#include <cstdlib>
#include <string>
using namespace std;

/*struct Person{
    string fname;
    string lname;
    Person (string fname = "", string lname = "") : fname(fname), lname(lname) {}

    friend ostream& operator<<(ostream& os, const Person& p){
        os << p.fname << " " << p.lname < ";";
        return os;
    }
};

struct PersonLess {
    bool operator()(const Person& p1, const Person& p2){
        if (p1.fname == p2.fname){
            return p1.lname < p2.lname;
        }
        return p1.fname < p2.fname
    }
};

struct PersonEqual {
    bool operator()(const Person& p1, const Person& p2){
        return (p1.fname == p2.fname && p1.lname == p2.lname);
    }
};*/

int main()
{
    OrderedList<int> l;
    for (int i = 0; i < 10; ++i){
        int v = rand() % 10;
        cout << v << " ";
        l.insert(v);

    }
    l.listItems(cout);

     Iterator<int> it(l);
     while (it.hasNext()) {
     cout << it.next() << " ";
     }
     cout << endl;
}
