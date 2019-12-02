#include <cstdlib>
#include"Polynomial.h"

using namespace std;

int main()
{
    double a[]{1,2,-3};
    Polynomial p1(2,a);
    double b[]{1,2,3};
    Polynomial p2(2,b);
    cout << "p1\n"<<p1<<"p2\n"<<p2;
    cout <<"p1+p2"<<endl<<p1+p2;
    cout <<"p1-p2"<<endl<<p1-p2;
    cout <<"p1*p2"<<endl<<p1*p2;
    return (EXIT_SUCCESS);
}
