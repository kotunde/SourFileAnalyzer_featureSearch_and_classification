#include <iostream>
#include "Alkalmazott.h"
#include "Szemely.h"
#include "Manager.h"
#include <string>

using namespace std;

Manager::Manager(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor): 
	Alkalmazott(vezetekNev,keresztNev,szuletesiEv,munkakor){}

void Manager::addAlkalmazott(Alkalmazott *a)
{
	beosztottak.push_back(a);
}

void Manager::deleteAlkalmazott(Alkalmazott *a)
{
	for (int i = 0; i < beosztottakSzama(); ++i) {
		if (a == beosztottak[i]) {
			beosztottak.erase(beosztottak.begin() + i);
			break;
		}
	}
}

int Manager::beosztottakSzama()
{
	return beosztottak.size();
}

void Manager::print(ostream &os) const
{
	os << this->vezetekNev << " " << this->keresztNev << " "
		<< ", " << this->szuletesiEv << ", " <<
		this->munkakor << ", " << "beosztottak szama: "
		<< beosztottak.size() << endl;
}
