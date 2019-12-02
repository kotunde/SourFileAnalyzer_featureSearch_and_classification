#include "Alkalmazott.h"
#include "Szemely.h"
#include <iostream>
#include <string>
using namespace std;


Alkalmazott::Alkalmazott(string vnev,string knev,int szdat,string munkak): Szemely(vnev,knev,szdat),munka(munkak){
}


void  Alkalmazott::print(ostream& os) const{
    Szemely::print(os);
    os<<munka;
}
