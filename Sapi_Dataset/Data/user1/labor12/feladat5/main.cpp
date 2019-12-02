#include <iostream>
#include "Diak.h"
#include "Feldolgozas.h"
using namespace std;

int main()
{
    Feldolgozas f;

    f.beolvasDiakok("nevek.txt");
    f.beolvasJegyek("magyar.txt","matek.txt","roman.txt");

    f.print();

    return 0;
}
