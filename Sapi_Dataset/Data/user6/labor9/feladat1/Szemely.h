#pragma once
#ifndef SZEMELY_H
#define SZEMELT_H

#include <iostream>
#include <string>

using namespace std;

class Szemely {
protected:
	string vezetekNev;
	string keresztNev;
	int szuletesiEv;

public:
	Szemely(string, string, int);
	virtual void print(ostream&) const;

	friend ostream& operator<<(ostream &os, const Szemely& sz);
};

#endif /* SZEMELY_H */
