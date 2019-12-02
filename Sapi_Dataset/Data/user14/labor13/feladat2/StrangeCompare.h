//
// Created by attila on 17.12.2018.
//

#ifndef FV_OBJ3_STRANGECOMPARE_H
#define FV_OBJ3_STRANGECOMPARE_H
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class StrangeCompare
{
private:
    static map<char, int> order;//Karakterek sorrendje
    static bool compchar( const char c1, const char c2 )
    {
        char aa=toupper(c1);
        char bb=toupper(c2);
        return order[aa]<order[bb];
    }
public:
    StrangeCompare( const string& alphabet)
    {
        order.insert(pair<char,int>((char)32,0));
        for (int i=1; i<=alphabet.size(); ++i)
        {
            order.insert(pair<char,int>(alphabet[i],i));
        }
    }
    bool operator()( const string& s1, const string& s2 )
    {
        return lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end(),compchar);
    }
};

map<char,int> StrangeCompare::order;


#endif //FV_OBJ3_STRANGECOMPARE_H
