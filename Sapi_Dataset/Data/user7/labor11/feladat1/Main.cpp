#include <cstdlib>
#include <iostream>
#include <string>
#include "Iterator.h"
#include "OrderedList.h"

using namespace std;

struct Person{
	string fname;
	string lname;
	Person( string fname="", string lname=""):fname( fname ), lname( lname){}
	friend ostream& operator<<( ostream& os, const Person& p){
		os << p.fname << " " << p.lname <<endl; 
		return os;
	};
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
		return (p1.fname == p2.fname && p1.lname == p2.lname);
	}
};


int main(int argc, char** argv) {
	OrderedList<int> l;
	for( int i=0; i<10; ++i ){
		int v = rand() % 10;
		l.insert( v );
	}
	cout << "\nList using iterator: ";
	Iterator<int> it(l);
	while (it.hasNext()) {
		cout << it.next() << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		int t = rand() % 10;
		cout << "\nTorlendo: " << t << endl;
		l.remove(t);
		l.listItems(cout);
	}
	// person
	OrderedList<Person, PersonLess, PersonEqual> pl;
	pl.insert(Person("Balazs", "Istvan"));
	pl.insert(Person("Andras", "Eva"));
	pl.insert(Person("Balazs", "Emoke"));
	pl.insert(Person("Petres", "Andras"));
	pl.listItems(cout);
	Person pf("Balazs", "Emoke");
	cout << (pl.find(pf) ? "FOUND" : "NOT FOUND") << endl;
	return 0;
}