#include <cstdlib>
#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>
#include <algorithm>

Manager::Manager(string vezetek, string kereszt, int ev, string munka):Alkalmazott(vezetek,kereszt,ev,munka){
}

void Manager::addAlkalmazott(Alkalmazott* a){
beosztottak.push_back(a);
}

void Manager::deleteAlkalmazott(Alkalmazott* a ){
beosztottak.erase(find(beosztottak.begin(),beosztottak.end(),a));
}

int Manager::beosztottakSzama(){
return beosztottak.size();
}

void Manager::print(ostream& out){
Alkalmazott:print(out);
out << this->beosztottakSzama();
out << endl;
}
