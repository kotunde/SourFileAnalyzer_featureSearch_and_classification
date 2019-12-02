#include <iostream>
#include <string>
#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>

using namespace std;

Manager::Manager(string vN, string kN, int szE, string mK) :
	Alkalmazott(vN, kN, szE, mK) {};

void Manager::addAlkalmazott(Alkalmazott* alk) {
	this->beosztottak.push_back(alk);
}
void Manager::deleteAlkalmazott(Alkalmazott* alk) {
	for (int i = 0; i < this->beosztottak.size(); ++i) {
		if (this->beosztottak[i] == alk) {
			this->beosztottak.pop_back();
		}
	}
}
int Manager::beosztottakSzama() const {
	return this->beosztottak.size();
}
void Manager::print(ostream& out) {
	Alkalmazott::print(out);
	out << "Beosztottak szama:" << beosztottak.size()<< endl;
	//out << this->vezetekNev << " " << this->keresztNev << " , " << this->szuletesiEv << ", " << this->munkakor << this->beosztottakSzama << endl;
}