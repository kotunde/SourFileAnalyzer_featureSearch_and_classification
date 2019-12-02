#ifndef STRANGECOMPARE_H_INCLUDED
#define STRANGECOMPARE_H_INCLUDED
#include <map>
#include <string>
#include <algorithm>
using namespace std;
class StrangeCompare
{
private:
    static map<char, int> order;//Karakterek sorrendje
    static bool compchar( const char c1, const char c2 )// {Kod}
    {
        return order[c1]<order[c2];
    }
public:
    StrangeCompare( const string& alphabet)
    {
        //this->order=alphabet;
        order[' ']=0;
        for(int i=0;i<alphabet.length();++i){
            order[alphabet[i]]=i+1;
        }
    }

    bool operator()( const string& s1, const string& s2 )
    {
        lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end(),compchar);
    }

};
    map<char,int>  StrangeCompare::order;


#endif // STRANGECOMPARE_H_INCLUDED
