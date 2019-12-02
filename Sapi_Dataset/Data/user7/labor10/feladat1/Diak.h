#pragma once

#ifndef DIAK_H
#define DIAK_H

#include <iostream>
#include <string>

using namespace std;

class Diak {
private:	
	string vnev;
	string knev;
	double atlag;
public:
	Diak(string vN, string kN, double avg);
	double getAtlag()const;
	string getVnev()const;
	string getKnev()const;
	friend ostream& operator<<(ostream& out, Diak& d);
	friend istream& operator>>(istream& in, Diak& d);
	friend bool operator<(const Diak &d1, const Diak &d2);

};
#endif // !DIAK_H
