#ifndef FELDOLGOZAS_H_INCLUDED
#define FELDOLGOZAS_H_INCLUDED
#include <map>
#include "Diak.h"
using namespace std;

class Feldolgozas{
private:
    map<double,Diak> diakok;
public:
    Feldolgozas();

    void beolvasDiakok(string);
    void beolvasJegyek(string,string,string);

    void print() const;
};

#endif // FELDOLGOZAS_H_INCLUDED
