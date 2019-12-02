#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <bitset>
#define mod 1000000009
using namespace std;

int num[1000];

int main()
{
    int t, i, j, n;
    cin>>t;
    for(j=1; j<=t; j++)
    {
        int n;
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>num[i];
        }
        for(i=0; i<n; i++)
        {
            if(num[i]==i)
                break;
        }
        if(i==n)
            cout<<"Case #"<<j<<": "<<"GOOD\n";
        else
            cout<<"Case #"<<j<<": "<<"BAD\n";
    }
    return 0;
}
