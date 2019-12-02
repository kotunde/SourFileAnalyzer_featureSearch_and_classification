//
// Created by attila on 26.11.2018.
//

#ifndef SZARMAZTATAS_ALKALMAZOTT_H
#define SZARMAZTATAS_ALKALMAZOTT_H

#include <iostream>
#include "Szemely.h"

using namespace std;

class Alkalmazott:public Szemely{
private:
    string munkakor;
public:

    Alkalmazott(string vnev, string knev, int szul_ev, string munkakor):
                Szemely(vnev,knev,szul_ev),munkakor(munkakor){}
    virtual void print(ostream& os=cout) const;
};
#endif //SZARMAZTATAS_ALKALMAZOTT_H
