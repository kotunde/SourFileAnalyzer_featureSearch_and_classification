#ifndef SZEMELY_H
#define SZEMELY_H

#include <iostream>
#include <string>

using namespace std;

class Szemely {
public:
	Szemely(string vezeteknev, string keresztnev, int ev);
	virtual void print(ostream&) const;
	friend ostream & operator <<(ostream& out, const Szemely& what);
protected:
	string vezetekNev;
	string keresztNev;
	int szuletesiEv;
};


#endif // !SZEMELY_H