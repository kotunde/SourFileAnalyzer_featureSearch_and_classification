#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("be.txt");
    vector< string > sor;
    string szo;
    while( fin>>szo)
    {
        sor.push_back(szo);
    }
    sort(sor.begin(),sor.end());

    for(int i=0;i<sor.size();++i){
        cout<<sor[i]<<" ";
    }
    cout<<endl;
    while(next_permutation(sor.begin(),sor.end())){
        for(int i=0;i<sor.size();++i){
        cout<<sor[i]<<" ";
    }
        cout<<endl;
    }
    return 0;
}
