#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
    double c[]{1,2,0,1}; Polynomial p1(3,c);
    Polynomial p2(p1);
    /*cout << p2;
    Polynomial p3 = std::move(p2);
    cout << p3;
    cout << "A polinom fokszama: " << p1.degree() << endl;
    cout << "A polinom erteke ha x = 1: " << p1.evaluate(1) << endl;
    Polynomial p3 = -p1;
    double c2[]{-2,3,0,1}; Polynomial p3(3,c2);
    cout << p3 << " + " << p1 << " = ";
    cout << p3 * p1;*/
    //cout << p1;
    //Polynomial p3 = p1.derivative();
    //cout << p3;
    return 0;
}
