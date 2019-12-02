#ifndef FELVETELI_H_INCLUDED
#define FELVETELI_H_INCLUDED
#include "Diak.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class Felveteli{
private:
    int helyekSzama;
    vector<Diak> diakok;
public:
    Felveteli(int);
    Felveteli(const char* filename);
    void Beiratkozas(Diak);
    void RendezesABC();
    void RendezesAtlag();
    void kiiratas(ostream&);
    void bejutottak(ostream&);
};


#endif
