#ifndef ALKALMAZOTT_H_INCLUDED
#define ALKALMAZOTT_H_INCLUDED

#include <iostream>
#include"Szemely.h"
using namespace std;

class Alkalmazott:public Szemely{
private:
    string munkakor;
public:
    Alkalmazott(string vezetekNev,string keresztNev,int szuletesiEv,string munkakor);
    virtual void print(ostream& out)const;
};


#endif // ALKALMAZOTT_H_INCLUDED
