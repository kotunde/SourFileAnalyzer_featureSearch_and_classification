#include <cstdlib>
#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>

Szemely::Szemely(string vezetek,string kereszt,int ev){
this->vezetekNev=vezetek;
this->keresztNev=kereszt;
this->szuletesiEv=ev;
}

void Szemely::print(ostream& out){
out << this->vezetekNev << " " << this->keresztNev << " " << this->szuletesiEv << endl;
}
