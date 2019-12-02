#include <iostream>
#include "Feldolgozas.h"
#include "Diak.h"

using namespace std;

int main()
{   Feldolgozas f1;
    f1.olvasNev("nevek.txt");
    f1.olvasMatek("matek.txt");
    f1.olvasMagyar("magyar.txt");
    f1.olvasRoman("roman.txt");
    //f1.kiiratas();
    cout << "Sikeresen erettsegizettek szama: " << f1.szamitatlag();
    return 0;
}
