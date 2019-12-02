#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    vector<string> v;

    v.push_back("D");
    v.push_back("B");
    v.push_back("C");

    sort(v.begin(),v.end());
    for (auto& a: v){
        cout << a << " ";
    }
    cout << endl;

    while (next_permutation(v.begin(),v.end())){
        for (auto& a : v){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
