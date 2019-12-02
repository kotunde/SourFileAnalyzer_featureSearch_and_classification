#include "Alkalmazott.h"
#include <iostream>
#include <string>

using namespace std;

Alkalmazott::Alkalmazott(string vezeteknev, string keresztnev, int ev, string munkakor) : Szemely(vezeteknev, keresztnev, ev), munkakor(munkakor) {}

void Alkalmazott::print(ostream& out) const {
	out << this->vezetekNev << " " << this->keresztNev << ", " << this->szuletesiEv << ", " << this->munkakor << endl;
}