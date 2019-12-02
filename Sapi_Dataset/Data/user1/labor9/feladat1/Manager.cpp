#include "Manager.h"
#include <string>
#include <iostream>
#include <vector>

Manager::Manager(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor):
    Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor){}

void Manager::addAlkalmazott(Alkalmazott* a){
    this->beosztottak.push_back(a);
}

void Manager::deleteAlkalmazott(Alkalmazott* a){
    int i = 0;
    while ((i < this->beosztottakSzama()) && this->beosztottak[i] != a){
        ++i;
    }
    this->beosztottak.erase(this->beosztottak.begin()+i);
}

int Manager::beosztottakSzama() const{
    return beosztottak.size();
}

void Manager::print(ostream& os) const {
    Alkalmazott::print(os);
    os << " beoszottak szama: " << this->beosztottakSzama();
}

