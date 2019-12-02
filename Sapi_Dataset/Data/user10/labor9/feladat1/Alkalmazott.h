#ifndef ALKALMAZOTT_H_INCLUDED
#define ALKALMAZOTT_H_INCLUDED
#include "Szemely.h"
using namespace std;
class Alkalmazott : public Szemely{
protected:
    string munkakor;
public:
    Alkalmazott(string, string, int, string);
    virtual void print(ostream&) const;
};


#endif // ALKALMAZOTT_H_INCLUDED
