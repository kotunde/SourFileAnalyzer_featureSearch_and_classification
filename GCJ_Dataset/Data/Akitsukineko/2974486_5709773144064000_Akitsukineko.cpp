
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int numTestCase;
    cin>>numTestCase;
    //cout<<"XD :"<<numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
        short flag = 0;
    	long double C = 0;
    	cin>>C;
        long double F = 0;
    	cin>>F;
        long double X = 0;
        cin>>X;
        long double time = 0;
        long double rate = 2;
        cout.precision(7);
        cout.setf( ios::fixed, ios::floatfield );
        
        while(flag==0)
        {
            if (X/rate>X/(rate+F)+C/rate) {
                time+=C/rate;
                rate+=F;
            }
            else
            {
                time+=X/rate;
                flag = -1;
            }
        }
        
    	cout<<"Case #"<<tc+1<<": "<<time<<endl;
    }

    return 0;
}

