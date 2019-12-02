#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Diak {
	string vnev;
	string knev;
	double atlag;
public:
	Diak() {}
	Diak(string vnev, string knev, double atlag) : vnev(vnev), knev(knev), atlag(atlag) {}
	double getAtlag() const{return atlag;}
    string getVnev() const{ return vnev;}
	string getKnev() const{return knev;}
	friend ostream& operator<<(ostream& os, const Diak& diak);
	friend istream& operator>>(istream& is, Diak& diak);
	//bool operator<(const Diak& , const Diak& );
};

#endif // DIAK_H_INCLUDED
