#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED
class Szemely{
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(string, string, int);
    void print(ostream& out);
};



#endif // SZEMELY_H_INCLUDED
