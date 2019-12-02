#include <iostream>
#include "Polinomial.h"
using namespace std;

int main()
{   double c[] {1,2,1};
    Polynomial p1 (2,c);
    cout<<p1;
    Polynomial p2(p1);
    cout<<endl;
    cout<<p2;
    cout<<endl;
    cout<<p1.evaluate(1);
    cout<<endl;
    cout<<-p1;
    double b[] {1,2,1,2};
    Polynomial p3(3,b);
    cout<<endl;
    cout<<p3;
    cout<<endl;
    cout<<p1+p3;
    cout<<endl;
    cout<<p1-p3;
    cout<<endl;
    cout<<p1*p2;
    return 0;
}
