#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void print(vector<string> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<string> szavak;
    ifstream f("szavak.txt");
    string szo;
    while(f>>szo){
        szavak.push_back(szo);
    }
    cout<<"Szavak:  ";
    print(szavak);
    cout<<"\n\nPermutaciok:\n\n";
    sort(szavak.begin(), szavak.end());
    do{
        print(szavak);
    }while(next_permutation(szavak.begin(), szavak.end()));

    return 0;
}
