#include <iostream>
using namespace std;

int main()
{
    int t,c;
    cin>>t;
    c = 1;
    int a,b,k;
    int i,j;
    while(c<=t)
    {
        cin>>a;
        cin>>b;
        cin>>k;
        int cnt=0;
        for(i=0; i<a; i++)
            for(j=0; j<b; j++)
                if( (i&j)<k)
                    cnt++;
        cout<<"Case #"<<c<<": "<<cnt<<endl;
        c++;
    }
    return 0;
}
