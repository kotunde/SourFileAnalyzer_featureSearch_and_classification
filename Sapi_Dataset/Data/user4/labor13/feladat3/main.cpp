#include <iostream>
#include <map>
#include <utility>
#include<fstream>
#include<string.h>
#include<sstream>
#include <set>
#include"StrangeCompare.h"

using namespace std;

void elsofeladat(){
    vector<string> v;
    v.push_back("korte");
    v.push_back("alma");
    v.push_back("szilva");
    sort(v.begin(),v.end());
    do {
        cout << v[0] <<" "<<v[1] <<" "<<v[2]<< endl;
    } while (next_permutation(v.begin(),v.end()));
}

void masodikfeladat(){
    vector<char> v;

    v.push_back('A');
    v.push_back('E');
    v.push_back('K');
    v.push_back('M');
    v.push_back('T');
    sort(v.begin(),v.end());
    int k=1;
    do {
        string str(v.begin(),v.end());
        if (str=="MATEK"){
            cout<<"MATEK a: "<< k <<". permutacio"<<endl;
            break;
        }
        k=k+1;
    } while (next_permutation(v.begin(),v.end()));
}

int main()
{
    cout<<"1------------------------\n";
    elsofeladat();
    cout<<"2------------------------\n";
    masodikfeladat();
    cout<<"3------------------------\n";
    ifstream ifs("bemenet.txt");
    string line;
    string abc;
    getline(ifs,abc);
    //StrangeCompare stringComp(abc);
    set<string,StrangeCompare> s(abc);
    while(  getline(ifs,line) )
    {
        s.insert(line);

    }

    for( auto& x: s )
    {
        cout<< x<<endl;
    }
    return 0;
}
