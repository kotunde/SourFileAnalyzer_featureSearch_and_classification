#include "manager.h"

Manager::Manager(string vezetekNev,string keresztNev,int szuletesiEv,string munkakor):
    Alkalmazott(vezetekNev,keresztNev,szuletesiEv,munkakor){
}

void Manager::print(ostream& os) const{
    Alkalmazott::print(os);
    os<<", beosztottak szama: "<<this->beosztottakSzama();
}

void Manager::addAlkalmazott(Alkalmazott* a){
    this->beosztottak.push_back(a);
}

void Manager::deleteAlkalmazott(Alkalmazott* a){
    for(unsigned int i=0; i<this->beosztottak.size(); i++){
        if(this->beosztottak[i]==a){
            this->beosztottak.erase(this->beosztottak.begin()+i);
        }
    }
}

int Manager::beosztottakSzama() const{
    return this->beosztottak.size();
}
