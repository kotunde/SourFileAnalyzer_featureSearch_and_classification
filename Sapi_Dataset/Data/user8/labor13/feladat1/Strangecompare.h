#ifndef _STRANGECOMPARE_H
#define _STRANGECOMPARE_H
#include <map>
#include <string>
#include <algorithm>
#include <iostream>


using namespace std;
class StrangeCompare {
private:
    static map<char, int> order;//Karakterek sorrendje
    static bool compchar( const char c1, const char c2 )
    {
        return order[c1] < order[c2];
    }
public:
        StrangeCompare( const string& alphabet);
        bool operator()( const string& s1, const string& s2 ) {
            return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), compchar);
        };

};
map<char,int> StrangeCompare::order;

StrangeCompare::StrangeCompare(const string& alpha)
{
    order[' ']=0;
    for(int i=1;i<=alpha.size(); i++)
    {
        order[alpha.at(i-1)] = i;

    }

//    for (auto x: order){
//        cout<<x.first<<" "<<x.second<<endl;
//    }
}

#endif /* _STRANGECOMPARE_H */
