
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main()
{
    int numTestCase;
    cin>>numTestCase;
    //cout<<"XD :"<<numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
        bool flag = false;
    	int N = 0;
        int A = 0;
        int B = 0;
        int K = 0;
    	cin>>A;
        cin>>B;
        cin>>K;
        int small = 0;
        int big = 0;
        int result = 0;
        
        
        if (B>A) {
            big = B;
            small = A;
        }
        else
        {
            big = A;
            small = B;
        }
        
        for(int i = 0; i<big; i++)
        {
            for (int j = 0; j<small; j++) {
                if ((i&j)<K) {
                    result++;
                }
            }
            
        }
        

        cout<<"Case #"<<tc+1<<": "<<result<<endl;

    }

    return 0;
}

