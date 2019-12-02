#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    vector <char>v;
    char k;
    char h[]= {'M','A', 'T','E','M','A','T','I','K','A'};
    ifstream fin("be.txt");
    while (fin>>k)
    {
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    cout<<"1:";
    for(int m=0; m<v.size(); ++m)
    {
        cout<<v[m];
    }
    int j=2,save,l=0;
    cout<<endl;

    while (next_permutation(v.begin(),v.end()))
    {
        cout<<j<<":";
        for(int i=0; i<v.size(); ++i)
        {
            cout<<v[i];
            if(v[i]==h[i])
            {
                l++;
            }

        }
        cout << endl;
        if(l == 5)
        {
            save=j;
        }
        j++;
        l=0;
    }
    cout<<save;
    return 0;
}
