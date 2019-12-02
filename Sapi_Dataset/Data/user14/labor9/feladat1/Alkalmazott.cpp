//
// Created by attila on 26.11.2018.
//

#include "Alkalmazott.h"

void Alkalmazott::print(ostream &os) const
{
    Szemely::print(os);
    os << " " << this->munkakor;
}
