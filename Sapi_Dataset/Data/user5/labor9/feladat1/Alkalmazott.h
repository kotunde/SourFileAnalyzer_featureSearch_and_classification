#pragma once
#include <iostream>
#include "Szemely.h"

using namespace std;

class Alkalmazott : public Szemely {
protected:
	string munkakor;
public:
	Alkalmazott(string vNev, string kNev, int szEv, string mk): Szemely(vNev, kNev, szEv), munkakor(mk){}
	virtual void print(ostream& os) const;
};
