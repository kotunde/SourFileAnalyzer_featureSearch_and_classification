#ifndef FELVETELI_H_INCLUDED
#define FELVETELI_H_INCLUDED
#include "diak.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Felveteli
{
private:
    int helyekSzama;
    vector<Diak> diakok;

public:
    Felveteli(int);
    Felveteli(const char*);
    void beiratkozas(Diak);
    void rendezesABC();
    void rendezesAtlag();
    void kiiratas(ostream&);
    void bejutottak(ostream&);
};

struct EntityComparator{
    int property;
    EntityComparator(int prop): property(prop){}
    bool operator()(Diak& di, Diak& de)
    {
        if(property == 1)
        {
            //ABC sorrendben
            return di<de;


        }
        if(property == 2){
            //atlag alapjan
            return di.getAtlag() > de.getAtlag();
        }

        return false;
    }
};


#endif // FELVETELI_H_INCLUDED
