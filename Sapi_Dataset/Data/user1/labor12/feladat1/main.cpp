#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <functional>

using namespace std;

int main()
{
    auto comp = [](string x, string y){ return x > y; };
    set<string,decltype(comp)> s(comp);
    set<string,greater<string>> DecreasingStringSet;

    s.insert("korte");
    s.insert("alma");
    s.insert("eper");
    s.insert("szilva");
    for (auto& x: s ){
        cout << x << " ";
    }
    cout << endl;

    DecreasingStringSet.insert("korte");
    DecreasingStringSet.insert("alma");
    DecreasingStringSet.insert("eper");
    DecreasingStringSet.insert("szilva");
    for (auto& x: DecreasingStringSet ){
        cout << x << " ";
    }

    return 0;
}
