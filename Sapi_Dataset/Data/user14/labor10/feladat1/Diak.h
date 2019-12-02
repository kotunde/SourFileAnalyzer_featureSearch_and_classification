//
// Created by attila on 26.11.2018.
//

#ifndef DIAK_DIAK_H
#define DIAK_DIAK_H

#include <iostream>
using namespace std;

class Diak{
private:
    string vnev;
    string knev;
    double atlag;
public:
    Diak(string vnev="", string knev="",double atlag=0.0):
    vnev(vnev),knev(knev),atlag(atlag){}
    double getAtlag()const;
    string getVnev()const;
    string getKnev()const;
    friend ostream& operator<<(ostream&,const Diak&);
    friend istream& operator>>(istream&,Diak&);
    friend bool operator< (const Diak& d1, const Diak& d2);
};
#endif //DIAK_DIAK_H
