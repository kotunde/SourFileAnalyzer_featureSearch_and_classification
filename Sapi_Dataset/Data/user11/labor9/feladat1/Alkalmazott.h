#ifndef ALKALMAZOTT_H_INCLUDED
#define ALKALMAZOTT_H_INCLUDED

#include <iostream>
#include <string>
#include "Szemely.h"
using namespace std;


class Alkalmazott:public Szemely {
protected:
     string munka;
public:
    Alkalmazott(string,string,int,string);
   virtual void print( ostream& os)const ;

};



#endif // ALKALMAZOTT_H_INCLUDED
