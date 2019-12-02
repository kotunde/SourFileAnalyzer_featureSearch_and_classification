#include "Diak.h"
#include <string>

double Diak::getAtlag() const {
	return this->atlag;
}

string Diak::getVnev() const {
	return this->vnev;
}

string Diak::getKnev() const {
	return this->knev;
}

ostream& operator<< (ostream& os, const Diak& d) {
	os << d.getVnev() << " " << d.getKnev() << " " << d.atlag;
	return os;
}

istream& operator>> (istream& is, Diak & d)
{
	string line;
	getline(is, line);
	int pos;
	pos = line.find(" ");
	d.vnev = line.substr(0, pos);
	line = line.substr(pos);
	pos = line.find(" ");
	d.vnev = line.substr(0, pos);
	line = line.substr(pos);
	d.atlag = stod(line);
	return is;
}
