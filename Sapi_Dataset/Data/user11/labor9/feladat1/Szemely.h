#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Szemely{
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(string,string,int);
    virtual void print( ostream&) const;
    friend ostream& operator<<(ostream& ,const Szemely& );


};


#endif // SZEMELY_H_INCLUDED
