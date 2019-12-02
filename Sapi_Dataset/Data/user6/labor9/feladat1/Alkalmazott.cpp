#include "Alkalmazott.h"
#include "Szemely.h"
#include <iostream>

using namespace std;

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor)
	:	Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor){}

void Alkalmazott::print(ostream &os) const
{
	os << this->vezetekNev << " " << this->keresztNev <<
		", " << this->szuletesiEv << ", " << this->munkakor << endl;
}

