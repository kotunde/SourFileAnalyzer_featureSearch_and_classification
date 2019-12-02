#ifndef PONTHALMAZ_H
#define PONTHALMAZ_H

#include "Pont.h"
#include <vector>

using namespace std;

class PontHalmaz{
    vector<Pont>   pontok;          ///pontok
    int n;                          ///különböző pontok száma
    vector<double> tavolsagok;      ///pontok kozotti tavolsagok

    //segédfüggvény
    void tavolsagSzamitas();
public:
    PontHalmaz( int n = 100 );      ///konstruktor: előállítja a pontok tömböt,
                                    ///kiszámítja a távolságokat (tavolsagok tömb)
    double maxTavolsag()   const;   ///maximum kiválasztás a tavolsag tömbből
    double minTavolsag()   const;   ///minimum kiválasztás a tavolsag tömbből

    int tavolsagokSzama()  const;   ///összesen hány távolság értelmezhető n
                                    ///különböző pont között

    void printPontok()     const;   ///a pontok tároló kiíratása
    void printTavolsagok() const;   ///a tavolsagok tároló kiíratása

    void rendezPontokX();           ///növekvő sorrendbe rendezi a pontokat x
                                    ///koordináta szerint
    void rendezPontokY();           ///u. a. y koordináta szerint
    void rendezTavolsagok();        ///a tavolsagok tároló rendezése

    int kulonbozoTavolsagokSzama(); ///hány darab különböző távolságot tartalmaz
                                    ///a tavolsagok tömb
};
#endif      /* PONTHALMAZ_H */
