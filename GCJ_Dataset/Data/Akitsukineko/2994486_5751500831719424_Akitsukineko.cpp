
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
    	cin>>N;
        vector<string> set;
        vector< vector<char> > compchar;
        vector< vector<int> > compint;
        
        //outlets
        for (int i = 0; i < N; i++)
        {
            string a;
            cin>>a;
            set.push_back(a);
            //cout<<a[i]<<endl;
        }
        
        for (int j = 0; j < N; j++)
        {
        
            vector<char> tmpstr;
            tmpstr.push_back(set[j][0]);
            vector<int> tmpint;
            tmpint.push_back(1);
        
            for (int i = 1; set[j][i]!=NULL; i++)
            {
                if (set[j][i]!=set[j][i-1]) {
                    tmpstr.push_back(set[j][i]);
                    tmpint.push_back(1);
                }
                else
                    tmpint[tmpint.size()-1]++;
            
            }
            compchar.push_back(tmpstr);
            compint.push_back(tmpint);
        }
        

        
        int result = 0;
        
        for (int i = 1; i<N && !flag; i++) {
            if(compchar[i].size()!=compchar[0].size())
                flag=true;
            else
            {
                for (int j = 0; j<compchar[i].size(); j++) {
                    if(compchar[i][j]!=compchar[0][j])
                        flag=true;
                }
            }
        }
        
        for (int j = 0; j<compchar[0].size(); j++) {
            int sum = 0;
            for (int i = 0; i<N; i++) {
                sum += compint[i][j];
            }
            for (int i = 0; i<N; i++) {
                if (compint[i][j]>(sum/N)) {
                    result += compint[i][j]-(sum/N);
                }
                else
                    result += (sum/N)-compint[i][j];
            }
            
        }
        
        
        if (flag) {
            cout<<"Case #"<<tc+1<<": Fegla Won"<<endl;
        }
        else
            cout<<"Case #"<<tc+1<<": "<<result<<endl;

    }

    return 0;
}

