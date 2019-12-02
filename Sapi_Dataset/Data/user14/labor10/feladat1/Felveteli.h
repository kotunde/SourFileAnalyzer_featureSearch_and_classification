//
// Created by attila on 26.11.2018.
//

#ifndef DIAK_FELVETELI_H
#define DIAK_FELVETELI_H

#include <iostream>
#include "Diak.h"
#include <vector>
using namespace std;

class Felveteli{
private:
    int helyekSzama;
    vector <Diak> diakok;
public:
    Felveteli(int helyszam=0):helyekSzama(helyszam){}
    Felveteli(string);
    void beiratkozas(Diak);
    void rendezesABC();
    void rendezesAtlag();
    void kiiratas(ostream& =cout);
    void bejutottak(ostream& =cout);
};

#endif //DIAK_FELVETELI_H
