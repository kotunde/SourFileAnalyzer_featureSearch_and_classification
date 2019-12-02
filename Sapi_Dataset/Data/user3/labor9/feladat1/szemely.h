#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Szemely{
    protected:
        string vezetekNev, keresztNev;
        int szuletesiEv;
    public:
        Szemely(string vezetekNev="",string keresztNev="",int szuletesiEv=0):
            vezetekNev(vezetekNev), keresztNev(keresztNev),szuletesiEv(szuletesiEv){
        }
        virtual void print(ostream& os=cout) const;
        friend ostream& operator<<(ostream& os, const Szemely& sz);
};

#endif // SZEMELY_H_INCLUDED
