#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED
#include <iostream>

using namespace std;

class Szemely{
private:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(string vezetekNev,string keresztNev,int szuletesiEv);
    virtual void print(ostream& out)const;
    friend ostream & operator <<(ostream& out, const Szemely& sz) ;
};


#endif // SZEMELY_H_INCLUDED
