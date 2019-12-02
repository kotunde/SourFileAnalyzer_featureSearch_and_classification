#include "Manager.h"
#include <iostream>

using namespace std;


void Manager :: addAlkalmazott (Alkalmazott * x)
{
    this->v.push_back(x);
}

void Manager :: deleteAlkalmazott (Alkalmazott * x)
{
    for (int i = 0 ; i<this->v.size(); i++)
    {
        if (v[i] == x)
        {
            v.erase(v.begin()+i,v.begin()+i+1);
            break;
        }

    }
}

int Manager :: beosztottakSzama () const
{
    return this->v.size();
}

void Manager :: print(ostream & os) const
{
    Alkalmazott :: print(os);
    os<<" beosztottak szama: "<<beosztottakSzama();
}
