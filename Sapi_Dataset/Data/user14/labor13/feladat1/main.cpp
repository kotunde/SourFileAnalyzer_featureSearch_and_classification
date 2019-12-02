#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    ifstream infile;
    infile.open("input.txt");
    vector<string> v;
    while (!infile.eof())
    {
        getline(infile,str);
        v.push_back(str);
    }
    sort(v.begin(),v.end());
    do
    {
        for (auto& it: v)
        {
            cout << it << " ";
        }
        cout << endl;
    }while (next_permutation(v.begin(),v.end()));

    return 0;
}