//
// Created by attila on 12.11.2018.
//

#ifndef SZERZO_KONYV_H
#define SZERZO_KONYV_H

#include "Szerzo.h"
#include <vector>
#include <string>

using namespace std;

class Konyv
{
private:
    string cim;
    vector <Szerzo> Szerzok;
    int kiadasi_ev;
public:
    Konyv(string cim,int ev);
    string getCim() const;
    void setCim(string);
    int getKiadasi_ev() const;
    void setKiadasi_ev(int);
    void addSzero(Szerzo&);
    friend ostream& operator<<(ostream& os, const Konyv& konyv);
    int getSzerzoSzam();
    Szerzo operator[](int index);
    friend int operator<(Konyv&, Konyv&);



};

#endif //SZERZO_KONYV_H
