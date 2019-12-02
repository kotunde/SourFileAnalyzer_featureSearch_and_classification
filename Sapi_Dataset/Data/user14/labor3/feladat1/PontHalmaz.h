//
// Created by tuni on 10/8/18.
//

#ifndef LABOR3_1_PontHALMAZ_H
#define LABOR3_1_PontHALMAZ_H

#include "Pont.h"
#include <vector>

using namespace std;

class PontHalmaz {
    vector<Pont> Pontok;                //Pontok
    int n;                              //különböző Pontok száma
    vector<double> tavolsagok;          //Pontok kozotti tavolsagok
    //segédfüggvény
    void tavolsagSzamitas();
public:
    PontHalmaz( int n = 100 );         //konstruktor: előállítja a Pontok tömböt,
                                        //kiszámítja a távolságokat (tavolsagok tömb),
    double maxTavolsag()   const;       //maximum kiválasztás a tavolsag tömbből
    double minTavolsag()   const;       //minimum kiválasztás a tavolsag tömbből
    int tavolsagokSzama()  const;       //összesen hány távolság értelmezhető n különböző Pont között

    void printPontok()     const;       //a Pontok tároló kiíratása
    void printTavolsagok() const;       //a tavolsagok tároló kiíratása
    void rendezPontokX();               //növekvő sorrendbe rendezi a Pontokat x koordináta szerint
    void rendezPontokY();               //u. a. y koordinátaszerint
    void rendezTavolsagok();            //a tavolsagok tároló rendezése
    int kulonbozoTavolsagokSzama();     //hány darab különböző távolságot tartalmaz a tavolsagok tömb
};

#endif //LABOR3_1_PontHALMAZ_H
