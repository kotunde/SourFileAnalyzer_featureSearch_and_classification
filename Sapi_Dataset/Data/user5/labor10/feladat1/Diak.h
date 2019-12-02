#pragma once
#include <iostream>

using namespace std;

class Diak {
private:
	string vnev, knev;
	double atlag;
public:
	Diak(string vnev, string knev, double atlag): vnev(vnev), knev(knev), atlag(atlag){}
	double getAtlag() const;
	string getVnev() const;
	string getKnev() const;
	
	friend ostream& operator<<(ostream& os, const Diak& d);
	friend istream& operator>>(istream& is, Diak& d);
};