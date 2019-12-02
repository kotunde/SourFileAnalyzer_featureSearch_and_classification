#pragma once
#include <iostream>
#include <string>

using namespace std;

class Diak {
	string vnev, knev;
	double matek = 0, magyar = 0, roman = 0;
	double atlag;
public:
	Diak(string vnev, string knev): vnev(vnev), knev(knev){}
	friend istream& operator>>(istream& is, Diak& d);
	friend ostream& operator<<(ostream& os, const Diak& d);
	string getVNev() const;
	string getKNev() const;
	void setMatek(double matek);
	void setMagyar(double magyar);
	void setRoman(double roman);
	double getAVG() const;
	void calcAVG();
};