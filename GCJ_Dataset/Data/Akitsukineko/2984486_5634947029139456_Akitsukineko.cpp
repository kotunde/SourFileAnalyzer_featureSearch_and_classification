
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bitcount(unsigned long long a)
{
    int result = 0;
    for( ; a != 0; a >>= 1 )
    {
        result += a&1;
    }
    return result;
}

int main()
{
    int numTestCase;
    cin>>numTestCase;
    //cout<<"XD :"<<numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
        
    	int N = 0;
    	cin>>N;
        int L = 0;
    	cin>>L;

        unsigned long long max[N][N];
        unsigned long long out[N];
        unsigned long long dev[N];
        
    

        //outlets
        for (int i = 0; i < N; i++)
        {
            cin>>out[i];

            //cout<<out[i]<<" ";
        }
        //cout<<endl;

        //devices
        for (int i = 0; i < N; i++)
        {
            cin>>dev[i];

            for(int j = 0; j < N; j++)
            {
                max[i][j] = out[j] ^ dev[i];
            }
            //cout<<dev[i]<<" ";
        }
        //cout<<endl;

        std::vector<unsigned long long > tmp;

        for(int k = 0; k < N; k++)
        {
            
            for(int i = 1; i < N; i++)
            {
                bool done = false;
                for(int j = 0; j < N; j++)
                {
                    if(max[0][k]==max[i][j]) done = true;
                }
                if (done == true)
                {
                    tmp.push_back(max[0][k]);
                }
                else
                {
                    i = N;
                }
            }
        }


        if(tmp.size()==0)
        {
            cout<<"Case #"<<tc+1<<": NOT POSSIBLE"<<endl;
        }
        else
        {
            std::vector<unsigned long long > tmp2;

            for(int k = 0; k < tmp.size(); k++)
            {
                bool map[N];
                for(int i = 0; i < N; i++)
                {
                   map[i] = false;
                }
             
                for(int i = 0; i < N; i++)
                {
                    for(int j = 0; j < N; j++)
                    {
                        if(max[0][k]==max[i][j]) map[j] = true;
                    }
                }

                for(int i = 1; i < N; i++)
                {
                    //cout<<map[i];
                    map[0] = map[0]&map[i];
                }
                if(map[0]==true)
                {
                    tmp2.push_back(tmp[k]);
                }
                //cout<<endl;
            }

            if(tmp2.size()==0)
            {
                cout<<"Case #"<<tc+1<<": NOT POSSIBLE"<<endl;
            }
            else
            {
                int min = bitcount(tmp2[0]);
                for(int k = 0; k < tmp2.size(); k++)
                {
                    int test = bitcount(tmp2[k]);
                    //cout<<" > "<<tmp2[k]<<": "<<test<<endl;
                    if(test<min) min = test;
                }
                cout<<"Case #"<<tc+1<<": "<<min<<endl;
            }

        }
        
    }

    return 0;
}

