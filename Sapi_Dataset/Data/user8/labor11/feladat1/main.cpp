#include <cstdlib>
#include "templist.h"
#include <iostream>
#include <string>

using namespace std;

struct Person {
    string fname;
    string lname;
    Person( string fname="", string lname=""):fname( fname ), lname( lname) {}
    friend ostream& operator<<( ostream& os, const Person& p) {
        os<<p.fname<<" "<<p.lname;
        return os;
    }

    bool operator==(const Person& p2)
    { if( this->fname == p2.fname )
            if(this->lname == p2.lname)
                return true;
        return false; }

};
struct PersonCompare {
    bool operator()( const Person& p1, const Person& p2) {
        if( p1.fname == p2.fname )
            return p1.lname < p2.lname;
        return p1.fname < p2.fname;
    }
};

struct PersonEqual {
    bool operator()( const Person& p1, const Person& p2) {
        if( p1.fname == p2.fname )
            if(p1.lname == p2.lname)
                return true;
        return false;
    }

};
int main(int argc, char** argv) {
    OrderedList<int> l;
    for( int i=0; i<10; ++i ) {
        int v = rand() % 10;
        l.insert( v );
        l.listItems(cout);
    }


    Iterator<int> it( l );
    while( it.hasNext() ) {
        cout<<it.next()<<"\t";
    }
    cout<<endl;


    l.remove(0);
    for( int i=0; i<10; ++i ) {
        int t = rand() % 10;
        cout<<"\nTorlendo: "<<t<<endl;
        l.remove( t );
        l.listItems(cout);
    }
// person
    OrderedList<Person, PersonCompare, PersonEqual> pl;
    pl.insert(Person("Balazs", "Istvan"));
    pl.insert(Person("Andras", "Eva"));

    pl.insert(Person("Balazs", "Emoke"));
    pl.insert(Person("Petres","Andras"));
    Person pers("Petres","Andras");
    pl.listItems( cout );
    pl.remove(pers);
    pl.listItems( cout );
    cout<<( pl.find(Person("Balazs", "Emoke")) ? "FOUND" : "NOT FOUND" )<<endl;
    return 0;
}
