#include <iostream>
#include"Alkalmazott.h"
using namespace std;

Alkalmazott :: Alkalmazott(string vezetekNev,string keresztNev,int szuletesiEv,string munkakor):
    Szemely(vezetekNev,keresztNev,szuletesiEv){
    this->munkakor = munkakor;
    }
void Alkalmazott :: print(ostream& out)const{
    Szemely::print(out);
    out << ", " << this->munkakor;
}
