#include <cstdlib>
#include "OrderedList.h"

#include <iostream>
#include <string>
using namespace std;



struct Person {
    string fname;
    string lname;
    Person(string fname = "", string lname = "") : fname(fname), lname(lname) {
    }
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.fname << " " << p.lname << ";";
        return os;
    }
};
struct PersonLess {
    bool operator()(const Person& p1, const Person& p2) {
        if (p1.fname == p2.fname)
            return p1.lname < p2.lname;
        return p1.fname < p2.fname;
    }
};
struct PersonEqual {
    bool operator()(const Person& p1, const Person& p2) {
        return (p1.fname == p2.fname && p1.lname == p2.lname );
    }
};
int main(int argc, char** argv)
{
    OrderedList<int> l;
    for (int i = 0; i < 10; ++i) {
        int v = rand() % 10;
        l.insert(v);
        l.listItems(cout);
        cout << endl;
    }

    cout << endl;
    //l.listItems(cout);
    for (int i = 0; i < 10; ++i)
    {
        int t = rand() % 10;
        cout << "\nTorlendo: " << t << endl;
        l.remove(t);
        l.listItems(cout);
    }
    cout << endl;
// person
    OrderedList<Person, PersonLess, PersonEqual> pl;
    pl.insert(Person("Balazs", "Istvan"));
    pl.insert(Person("Andras", "Eva"));
    pl.insert(Person("Balazs", "Emoke"));
    pl.insert(Person("Petres", "Andras"));
    pl.listItems(cout);
    Person pf("Balazs","Emoke");
    cout<<(pl.find(pf)? "FOUND": "NOT FOUND")<<endl;







//    OrderedList <int> l1;
//    cout <<l1.isEmpty() <<endl;
//    l1.insert(3);
//    l1.listItems(cout);
//    l1.insert(1);
//    cout << endl;
//    l1.listItems(cout);
//    l1.insert(2);
//    cout << endl;
//    l1.listItems(cout);
//    l1.insert(4);
//    cout << endl;
//    l1.listItems(cout);
//    l1.remove(3);
//    cout << endl;
//    l1.listItems(cout);
//    cout << endl;
//    cout << "Size: " << l1.size() << endl;
//    cout << l1.find(4);



    return 0;
}