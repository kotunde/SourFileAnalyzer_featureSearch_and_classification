
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int numTestCase;
    cin>>numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
        cout<<"Case #"<<tc+1<<": ";
    	int n = 0;
    	cin>>n;
        vector<float> Naomi, Naomi2;
        vector<float> Ken, Ken2;
        float tmp;
        for (int i = 0; i < n; i++) {
            cin>>tmp;
            Naomi.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            cin>>tmp;
            Ken.push_back(tmp);
        }
        
        sort (Naomi.begin(), Naomi.end());
        sort (Ken.begin(), Ken.end());
        
        copy(Naomi.begin(), Naomi.end(), back_inserter(Naomi2) );
        copy(Ken.begin(), Ken.end(), back_inserter(Ken2) );

        int result = 0;
        //Deceitful War
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (Naomi[j]>Ken[i]) {
                    result++;
                    Naomi[j]=-1;
                    break;
                }
            }
        }

        cout<<result<<" ";
        result = 0;
        //War
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if (Naomi2[i]<Ken2[j]) {
                    result++;
                    Ken2[j]=-1;
                    break;
                }
            }
        }
        
        cout<<n-result<<endl;
    }

    return 0;
}

