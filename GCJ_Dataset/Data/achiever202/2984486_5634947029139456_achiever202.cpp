#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <bitset>
#define mod 1000000009
using namespace std;

string in[10];
string out[10];

int main()
{
    int t, i, j, n, l, k;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n>>l;
        int count1 = 0, count2 = 0;
        for(j=0; j<n; j++)
        {
            cin>>in[j];
            int xor_ = 0;
            for(k=0; k<l; k++)
                xor_ = xor_^(in[j][k]-'0');
            //cout<<xor_<<" ";
            if(xor_==1)
                count1++;
        }
        //cout<<endl;
        for(j=0; j<n; j++)
        {
            cin>>out[j];
            int xor_ = 0;
            for(k=0; k<l; k++)
                xor_ = xor_^(out[j][k]-'0');
            //cout<<xor_<<" ";
            if(xor_==1)
                count2++;
        }
        //cout<<endl;
        if(count1==count2 || (n-count1)==count2)
        {
            int count = 0;
            int xor1 = 0, xor2 = 0;
            for(j=0; j<l; j++)
            {
                xor1 = xor2 = 0;
                for(k=0; k<n; k++)
                {
                    xor1 = xor1^(in[k][j]-'0');
                    xor2 = xor2^(out[k][j]-'0');;
                }
                if(xor1!=xor2)
                    count++;
            }
            cout<<"Case #"<<i<<": "<<count<<"\n";
        }
        else
            cout<<"Case #"<<i<<": "<<"NOT POSSIBLE\n";
    }
    return 0;
}
