#pragma once
#ifndef SZEMELY_H
#define SZEMELY_H

#include <iostream>
#include <string>

using namespace std;
class Szemely {
protected:
	string vezetekNev;
	string keresztNev;
	int szuletesiEv;
public:
	Szemely(string vN, string kN, int szE);
	virtual void print(ostream& out);
};
#endif // !SZEMELY.H