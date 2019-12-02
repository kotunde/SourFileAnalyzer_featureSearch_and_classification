#include "Manager.h"

void Manager::print(ostream & os) const
{
	os << this->vezetekNev << " " << this->keresztNev << ", " << this->szuletesiEv << " " << this->munkakor << "  beosztottak szama: " << this->beosztottakSzama();
}

void Manager::addAlkalmazott(Alkalmazott* a) {
	beosztottak.push_back(a);
}

void Manager::deleteAlkalmazott(Alkalmazott* a) {
	int p;
	for (int i = 0; i < beosztottak.size(); i++) {
		if (beosztottak[i] == a) {
			p = i;
		}
	}
	beosztottak.erase(beosztottak.begin() + p);
}

int Manager::beosztottakSzama() const {
	return beosztottak.size();
}