#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
using namespace std;

class Szemely
{
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;

public:
    Szemely(string, string, int);
    void virtual print(ostream&) const;
    friend ostream& operator<<(ostream &os, const Szemely& sz);
};

#endif // PERSON_H_INCLUDED
