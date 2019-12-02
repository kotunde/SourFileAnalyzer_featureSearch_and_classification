//
// Created by attila on 26.11.2018.
//

#include "Szemely.h"


void Szemely::print(ostream &os) const
{
    cout << this->vnev << " " << this->knev << ", " << this->szul_ev;

}

ostream &operator<<(ostream & os, const Szemely & sz)
{

    sz.print(os);
    return os;
}
