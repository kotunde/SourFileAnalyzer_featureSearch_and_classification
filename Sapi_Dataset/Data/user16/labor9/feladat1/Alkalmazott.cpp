#include "Alkalmazott.h"
#include <iostream>

using namespace std;

/*
Alkalmazott::Alkalmazott()
{

}*/

void Alkalmazott :: print(ostream & os) const
{
   Szemely :: print(os);
   os<<" "<<this->munkakor;
}
