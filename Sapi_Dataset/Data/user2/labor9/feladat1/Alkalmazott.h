#ifndef ALKALMAZOTT_H
#define	ALKALMAZOTT_H

#include <iostream>
#include "Szemely.h"
#include <string>

using namespace std;

class Alkalmazott : public Szemely {
public:
	Alkalmazott(string vezeteknev, string keresztnev, int ev, string munkakor);
	void print(ostream&) const;
protected:
	string munkakor;
};

#endif // !ALKALMAZOTT_H
