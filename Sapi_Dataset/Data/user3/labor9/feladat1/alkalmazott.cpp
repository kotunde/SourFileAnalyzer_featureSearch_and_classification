#include "alkalmazott.h"


Alkalmazott::Alkalmazott(string vezetekNev,string keresztNev,int szuletesiEv,string munkakor):
    Szemely(vezetekNev,keresztNev,szuletesiEv), munkakor(munkakor){
}

void Alkalmazott::print(ostream& os) const{
    Szemely::print(os);
    os<<", "<<this->munkakor;
}
