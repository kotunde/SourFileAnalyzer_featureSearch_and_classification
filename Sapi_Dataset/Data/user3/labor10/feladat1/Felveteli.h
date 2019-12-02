#ifndef FELVETELI_H
#define FELVETELI_H

#include "Diak.h"
#include <vector>
#include <iostream>

using namespace std;

class Felveteli
{
    public:
        Felveteli(int helyekSzama=0);
        Felveteli(const char* filename);
        void beiratkozas(Diak diak);
        void rendezesABC();
        void rendezesAtlag();
        void kiiratas(ostream& os=cout);
        void bejutottak(ostream& os=cout);
    private:
        int helyekSzama;
        vector<Diak> diakok;
};

#endif // FELVETELI_H
