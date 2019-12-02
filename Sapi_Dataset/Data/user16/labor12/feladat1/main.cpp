#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
//lambda expression
    auto comp = [](string x, string y)
    {
        return x > y;
    };
    set<string,decltype(comp)> s(comp);

    string gyumolcs;

    for (int i = 0 ; i<10 ; i++)
    {
        cin>>gyumolcs;
        s.insert(gyumolcs);
    }
    cout<<endl<<endl;



    for( auto& x: s )
    {
        cout<< x<<endl;
    }
    cout<<endl;
    return 0;
}
