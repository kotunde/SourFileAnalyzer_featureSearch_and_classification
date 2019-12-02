#include "Alkalmazott.h"
#include "Manager.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Manager::Manager(string vezeteknev, string keresztnev, int ev, string munkakor) :Alkalmazott(vezeteknev,keresztnev,ev,munkakor) {}

void Manager::addAlkalmazott(Alkalmazott* alk){
	this->alkalmazottak.push_back(alk);
}

void Manager::deleteAlkalmazott(Alkalmazott* alk) {
	for (int i = 0; i < this->alkalmazottak.size(); ++i) {
		if (this->alkalmazottak.at(i) == alk) {
			this->alkalmazottak.erase(this->alkalmazottak.begin() + i);
			break;
		}
	}
}

int Manager::beosztottakSzama() {
	return this->alkalmazottak.size();
}

void Manager::print(ostream& out) const {
	out << this->vezetekNev << " " << this->keresztNev << ", " << this->szuletesiEv << ", " << this->munkakor;
	out << "beosztottak szama: " << this->alkalmazottak.size() << endl;

}
