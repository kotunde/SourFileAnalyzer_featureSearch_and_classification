#include <iostream>
#include "Polynomial.h"


int main()
{

    int n=3;
    double tomb[n];
    for (int i=0; i<n; ++ i)
    {
        tomb[i]=i+1;
    }
    Polynomial p1(n-1,tomb);
    Polynomial p2=p1;
    cout << p1 << endl;
    cout << p2 <<endl;
    Polynomial p3 =p1+p2;
    cout << p3 <<endl;
    Polynomial p6=-p2;
    Polynomial p4 =p1-p6;
    cout << p4 <<endl;
    Polynomial p5 =p1*p2;
    cout << p5 <<endl;
    cout << p1.evaluate(2) << endl;
    cout << p1.derivative();


    return 0;
}