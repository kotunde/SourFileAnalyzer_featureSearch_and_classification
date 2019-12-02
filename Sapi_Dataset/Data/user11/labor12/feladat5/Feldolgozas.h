#ifndef FELDOLGOZAS_H_INCLUDED
#define FELDOLGOZAS_H_INCLUDED
#include <map>
#include <string>
#include "Diak.h"
using namespace std;
class Feldolgozas{
map<int,Diak> eretsegi;
public :
    void olvasNev(string filename);
    void olvasMagyar(string filename);
    void olvasRoman(string filename);
    void olvasMatek(string filename);
    void kiiratas();
    int szamitatlag();
};

#endif // FELDOLGOZAS_H_INCLUDED
