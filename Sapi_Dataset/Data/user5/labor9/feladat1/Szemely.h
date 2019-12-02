#pragma once
#include <iostream>
#include <string>

using namespace std;

class Szemely {
protected:
	string vezetekNev, keresztNev;
	int szuletesiEv;
public:
	Szemely(string vNev, string kNev, int szEv): vezetekNev(vNev), keresztNev(kNev), szuletesiEv(szEv){}
	virtual void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Szemely& sz);
};