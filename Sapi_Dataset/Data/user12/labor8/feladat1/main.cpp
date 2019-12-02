#include <iostream>
#include <ostream>
#include "polygon.h"

using namespace std;

int main()
{
    double x[]={1,2,3};
    double y[]={2,4,3};
    Polygon a(3,x,y);

    double d[]={2,5,3};
    double u[]={7,9,8};
    Polygon pol(3,d,u);

    cout << a;
    cout << a.length() << endl;
    cout << pol;
    cout << endl;
    pol=a;
    cout << pol;

    cout << endl;
    //Polygon alma(0, NULL, NULL);
    Polygon alma = a+pol;
    cout << alma;
    cout << endl;

    a.translate(1,1);
    cout << a;
    cout << endl;

    Polygon s(a);
    cout << s;

    return 0;
}
