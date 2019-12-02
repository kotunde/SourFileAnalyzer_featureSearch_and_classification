#include "Alkalmazott.h"
#include <string>
#include <iostream>

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string mk):
    Szemely(vezetekNev,keresztNev,szuletesiEv), munkakor(mk){}

void Alkalmazott::print(ostream& os) const {
    Szemely::print(os);
    os << " " << munkakor;
}
