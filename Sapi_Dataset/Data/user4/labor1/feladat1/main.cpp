#include <iostream>
#include <stdlib.h>
#include"functions.h"

using namespace std;

int main()
{
    /*for(int i = 0; i < 128; i++){
    cout << i << " egyes bitjeinek a szama = " << countBits(i) << endl;
    }

    int n=1;
    cout << n << endl;
    setBit(n,5);
    cout << n << endl;

    double a[]= {-2, -1, 3};
    cout << stddev(a,3) << endl;

    double a[] = {-2, -1, 3, 45, 999,6,98,112};
    double aa[] = {};
    double* b = max2(aa,0);
    cout << b[0] << " " << b[1] << endl;

    cout <<"String: ";
	cout <<capitalizeWords("aFnbiGh  kkHGa, il")<<endl;

    cout <<"Code: ";
	cout <<code("AbiGailZz")<<endl;
	*/
	cout <<"Splittext: \n";
	cout <<splitText("Apple Crain the BIG,  heroo")<<endl;

    return 0;
}
