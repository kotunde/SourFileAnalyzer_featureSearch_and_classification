//
// Created by attila on 26.11.2018.
//

#ifndef SZARMAZTATAS_SZEMELY_H
#define SZARMAZTATAS_SZEMELY_H

#include <iostream>
using namespace std;

class Szemely{
private:
    string vnev;
    string knev;
    int szul_ev;
public:
    //constructor
    Szemely(string vnev="", string knev="", int szul_ev=0):
                            vnev(vnev),knev(knev),szul_ev(szul_ev){}
    virtual void print(ostream& os=cout) const;
    friend ostream&operator<<(ostream& ,const Szemely&);
};

#endif //SZARMAZTATAS_SZEMELY_H
