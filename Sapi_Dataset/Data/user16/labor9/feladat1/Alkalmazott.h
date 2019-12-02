#ifndef ALKALMAZOTT_H
#define ALKALMAZOTT_H

#include <string>
#include <Szemely.h>



using namespace std;

class Alkalmazott : public Szemely
{
public:
   // Alkalmazott();
    Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor):
        Szemely(vezetekNev,keresztNev,szuletesiEv),munkakor(munkakor)
    {

    }

   void print(ostream & os) const;

protected:
    string munkakor;
};

#endif // ALKALMAZOTT_H
