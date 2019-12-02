#include <cstdlib>
#include "OrderedList.h"

#include <iostream>
#include <string>
#include<time.h>

using namespace std;

struct Person
{
    string fname;
    string lname;
    Person( string fname="", string lname=""):fname( fname ), lname( lname) {}
    friend ostream& operator<<( ostream& os, const Person& p)
    {
        os<<p.fname<<" "<<p.lname;
        return os;
    }
    string toString(){
        return fname + " " + lname;
    }
};
struct PersonCompare
{
    bool operator()( const Person& p1, const Person& p2)
    {
        if( p1.fname == p2.fname )
            return p1.lname < p2.lname;
        return p1.fname < p2.fname;
    }
};

struct Equal
{
    bool operator()( const Person& p1, const Person& p2)
    {
        return( p1.fname == p2.fname && p1.lname == p2.lname);
    }
};

int main(int argc, char** argv)
{
    OrderedList<int> l;
    srand(time(nullptr));
    for( int i=0; i<10; ++i )
    {
        int v = rand() % 10;
        l.insert( v );
    }
    l.listitems(cout);
    int x=1;
    if(l.find(x))
        cout<<"van 1es\n";
    // person
    OrderedList<Person, PersonCompare,Equal> pl;
    pl.insert(Person("Balazs", "Istvan"));
    pl.insert(Person("Andras", "Eva"));

    pl.insert(Person("Balazs", "Emoke"));
    pl.insert(Person("Petres","Andras"));
    pl.listitems( cout );

    Person person("Petres","Andras");
    if(pl.find(person))
        cout<<"szerepel "<<person.toString();
    else
        cout<<"nem szerepel "<<person.toString();

    return 0;
}
