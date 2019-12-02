#include <iostream>
#include "functions.h"

using namespace std;
int main()
{
    int n,i,x;
    double a[8];
    for(i=0; i<127; ++i){
    cout << countBits(i) << " ";}
    cout << endl;
    cin >> n >> x;
    cout << setBit(n,x);
    cout << endl;
    for(i=0; i<8; ++i){
        cin>>a[i];
    }
    double* b=max2(a,8);
        cout<<b[0]<< " "<<b[1];

    return 0;
}
