//
// Created by attila on 12.11.2018.
//

#include "Szerzo.h"
#include <ostream>
using namespace std;

Szerzo::Szerzo(string vnev, string knev)
{
    this->vezeteknev=vnev;
    this->keresztnev=knev;
}

string Szerzo::getVezeteknev() const
{
    return this->vezeteknev;
}

string Szerzo::getKeresztnev() const
{
    return this->keresztnev;
}

ostream &operator<<(ostream &os, const Szerzo &sz)
{
    os<<sz.vezeteknev << " " << sz.keresztnev;
    return os;
}
