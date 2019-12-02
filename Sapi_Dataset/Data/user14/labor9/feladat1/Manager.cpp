//
// Created by attila on 26.11.2018.
//

#include "Manager.h"
#include <vector>
#include <iostream>

using namespace std;

void Manager::addAlkalmazott(Alkalmazott * alk)
{
    this->beosztottak.push_back(alk);
}

void Manager::deleteAlkalmazott(Alkalmazott* a)
{
    int c=0;
    for (auto& it:beosztottak)
    {
        c++;
        if ( a == it)
        {
            beosztottak.erase(beosztottak.begin() + c);
        }
    }
}

int Manager::beosztottakSzama () const
{
    //query=const!!
    return beosztottak.size();
}

 void Manager::print(ostream &os) const {
    Alkalmazott::print(os);
    os << " beosztottak szama: " << beosztottakSzama();
}
