#include <iostream>
#include "Szemely.h"
#include <string>
using namespace std;

Szemely::Szemely(string vezetek,string kereszt,int ev){
    this->vezetekNev=vezetek;
    this->keresztNev=kereszt;
    this->szuletesiEv=ev;

 }
void Szemely::print(ostream& os) const{
    os<<this->vezetekNev<<", "<<this->keresztNev<<", "<<this->szuletesiEv;
}
ostream& operator << (ostream& os,const Szemely& sz) {
    sz.print(os);
    return os;
}
