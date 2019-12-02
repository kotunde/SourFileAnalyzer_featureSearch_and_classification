#ifndef PONTHALMAZ_H_INCLUDED
#define PONTHALMAZ_H_INCLUDED
#include "Pont.h"
#include <vector>

using namespace std;

class PontHalmaz{
    vector<Pont> pontok;
    int n;
    vector<double> tavolsagok;

    //segedfuggveny
    void tavolsagSzamitas();
public:
    PontHalmaz (int n = 100);
    double maxTavolsag() const;
    double minTavolsag() const;

    int tavolsagokSzama() const;

    void printPontok() const;
    void printTavolsagok() const;

    void rendezPontokX();

    void rendezPontokY();
    void rendezTavolsagok();

    int kulonbozoTavolsagokSzama();
};

#endif // PONTHALMAZ_H_INCLUDED
