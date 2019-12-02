#include <iostream>
#include"Szemely.h"
#include<vector>
#include"Alkalmazott.h"
#include"Manager.h"
using namespace std;

Manager :: Manager(string vezetekNev,string keresztNev,int szuletesiEv,string munkakor):
    Alkalmazott(vezetekNev,keresztNev,szuletesiEv,munkakor){}

void Manager :: addAlkalmazott(Alkalmazott* a){
    this->beosztottak.push_back(a);
}


void Manager::deleteAlkalmazott(Alkalmazott * a)
{
	for (int i = 0;i < beosztottak.size();i++)
	{
		if (beosztottak[i] == a)
			beosztottak.erase(beosztottak.begin() + i);
	}
}

int Manager :: beosztottakSzama(){
    this->beosztottak.size();
}
void Manager :: print(ostream& out)const{
    Alkalmazott :: print(out);
    out <<": " <<this->beosztottak.size();
}
