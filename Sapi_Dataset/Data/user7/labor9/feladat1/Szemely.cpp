#include <iostream>
#include <string>
#include "Szemely.h"

using namespace std;

Szemely::Szemely(string vN, string kN, int szE) {
	this->vezetekNev = vN;
	this->keresztNev = kN;
	this->szuletesiEv = szE;
}

void Szemely::print(ostream& out){
	out << this->vezetekNev << " " << this->keresztNev << " , " << this->szuletesiEv;
}
