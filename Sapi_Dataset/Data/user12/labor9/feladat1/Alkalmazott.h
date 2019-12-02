#include "Szemely.h"
#ifndef ALKALMAZOTT_H_INCLUDED
#define ALKALMAZOTT_H_INCLUDED
class Alkalmazott:Szemely{
protected:
    string munkakor;
public:
    Alkalmazott(string,string,int,string);
    void print(ostream& out);

};



#endif // ALKALMAZOTT_H_INCLUDED
