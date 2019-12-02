#ifndef FELVETELI_H_INCLUDED
#define FELVETELI_H_INCLUDED
#include <string>
#include "Diak.h"

using namespace std;

class Felveteli{
private:
    int helyekSzama;
    vector<Diak> diakok;
public:
    Felveteli(int);
    Felveteli(string);
    void beiratkozas(Diak);
    void rendezesABC();
    void rendezesAtlag();
    void kiiratas(ostream&);
    void bejutottak(ostream&);
};

#endif // FELVETELI_H_INCLUDED
