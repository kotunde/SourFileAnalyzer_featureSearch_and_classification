//
// Created by attila on 26.11.2018.
//

#ifndef SZARMAZTATAS_MANAGER_H
#define SZARMAZTATAS_MANAGER_H

#include <iostream>
#include <vector>
#include "Alkalmazott.h"

using namespace std;

class Manager: public Alkalmazott{
    vector<Alkalmazott* > beosztottak;
public:
    Manager(string vnev, string knev, int szul_ev, string munkakor):
    Alkalmazott(vnev,knev,szul_ev,munkakor){}
    void addAlkalmazott(Alkalmazott*);
    void deleteAlkalmazott(Alkalmazott*);
    int beosztottakSzama() const;
    virtual void print(ostream& os=cout)const;
};
#endif //SZARMAZTATAS_MANAGER_H
