#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    vector<string> v;

    v.push_back("A");
    v.push_back("E");
    v.push_back("K");
    v.push_back("M");
    v.push_back("T");

    sort(v.begin(),v.end());

    string s, x = "MATEK";
    int counter = 0, poz;

    while (next_permutation(v.begin(),v.end())){
        s = "";
        for (auto& a : v){
            s += a;
        }
        ++counter;
        cout << s << endl;
        if (s.compare(x) == 0){poz = counter;}
    }
    cout << x << " szo a " << poz << ". helyen all" << endl;

    return 0;
}
