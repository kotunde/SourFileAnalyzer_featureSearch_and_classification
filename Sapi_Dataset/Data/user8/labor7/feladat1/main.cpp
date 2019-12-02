#include <iostream>
#include "polynom.h"

using namespace std;

int main()
{
    double c[] {1,2,1};
    Polynomial p1(2,c);

    cout<<"p1: "<<p1;
    cout<<"p1 degree: "<<p1.degree()<<endl;
    cout<<"p1 in f(2): "<<p1.evaluate(2)<<endl;
    Polynomial p2 = (p1.derivative());
    //Polynomial p2 = std::move(p1.derivative());
    cout<<"p2: "<<p2;
    cout<<"p2 degree: "<<p2.degree()<<endl;
    cout<<"p2 in f(2): "<<p2.evaluate(2)<<endl;
    cout<<"p1 + p2: "<<p1+p2;
    cout<<"p1 - p2: "<<p1-p2;
    cout<<"p1 * p2: "<<p1*p2;


    return 0;
}
