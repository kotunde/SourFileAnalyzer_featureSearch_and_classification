#pragma once
#ifndef DIAK_H
#define DIAK_H

#include <iostream>
#include <string>
#include "Diak.h"

using namespace std;

class Diak {
private:
	string vnev;
	string knev;
	double atlag;

public:
	Diak();
	Diak(string vnev, string knev, double atlag);
	double getAtlag() const;
	string getVnev() const;
	string getKnev() const;

	friend ostream& operator <<(ostream &os, Diak &d);
	friend istream& operator >>(istream &is, Diak &d);
	friend bool operator<(const Diak&, const Diak&);
};



#endif /* DIAK_H */