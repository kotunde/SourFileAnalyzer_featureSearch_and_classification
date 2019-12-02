#ifndef ALKALMAZOTT_H_INCLUDED
#define ALKALMAZOTT_H_INCLUDED

#include "szemely.h"
#include <string>
#include <iostream>
using namespace std;

class Alkalmazott : public Szemely{
    protected:
        string munkakor;
    public:
        Alkalmazott(string vezetekNev,string keresztNev,int szuletesiEv, string munkakor);
        virtual void print(ostream& os=cout) const;
};

#endif // ALKALMAZOTT_H_INCLUDED
