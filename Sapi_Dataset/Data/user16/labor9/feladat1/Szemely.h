#ifndef SZEMELY_H
#define SZEMELY_H

#include<iostream>

#include <string>
using namespace std;

class Szemely
{
public:
    //Szemely();
    Szemely(string, string, int);
    virtual void print (ostream &) const ;
    friend ostream & operator<<(ostream & os, const Szemely & );
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;

};

#endif // SZEMELY_H
