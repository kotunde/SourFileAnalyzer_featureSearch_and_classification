#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <bitset>
#define mod 1000000009
using namespace std;

string words[100];

class type
{
    public:
    char ch;
    int num;

    type(char c, int i)
    {
        ch = c;
        num = i;
    }
};


int abs(int a)
{
    if(a<0)
        return -a;
    else
        return a;
}
int main()
{
    int t, i, j, l, a, b, k;
    cin>>t;
    for(l=1; l<=t; l++)
    {
        int count = 0;
        cin>>a>>b>>k;
        for(i=0; i<a; i++)
        {
            for(j=0; j<b; j++)
            {
                int ans = i&j;
                //cout<<i<<" "<<j<<" "<<ans<<endl;
                if(ans<k)
                    count++;
            }
        }
        cout<<"Case #"<<l<<": "<<count<<"\n";
    }
    return 0;
}
