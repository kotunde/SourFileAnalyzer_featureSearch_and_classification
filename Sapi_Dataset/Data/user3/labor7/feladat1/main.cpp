#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    double c[]{1,2,1};
    Polynomial p1(2,c);
    cout<<"p1: "<<p1;
    cout<<"p1(1): "<<p1.evaluate(1)<<endl;
    Polynomial d1=p1.derivative();
    cout<<"p1 derivalt: "<<d1;

    double c2[]{1,1,1,1};
    Polynomial p2(3,c2);
    cout<<"\np2: "<<p2;

    cout<<"\np1 + p2: "<<p1+p2;
    cout<<"\np1 - p2: "<<p1-p2;
    cout<<"\np1 * p2: "<<p1*p2;

    cout<<"\ncopy constructor:";
    Polynomial p3(p2);
    cout<<"\np3: "<<p3;

    double c4[]{1,1};
    Polynomial p4(1,c4);
    cout<<"\np4:" <<p4<<endl;

    double c5[]{-1,1};
    Polynomial p5(1,c5);
    cout<<"p5:" <<p5<<endl;

    cout<<"\np4 * p5: "<<p4*p5;

    return 0;
}
