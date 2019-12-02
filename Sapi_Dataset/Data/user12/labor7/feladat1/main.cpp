#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
    int degree = 4;
    double poli[4]={1,4,7,9};
    Polynomial P(degree,poli);
    cout << P << endl;
    cout << P.degree() << endl;
    cout << P.evaluate(3);
    return 0;
}
