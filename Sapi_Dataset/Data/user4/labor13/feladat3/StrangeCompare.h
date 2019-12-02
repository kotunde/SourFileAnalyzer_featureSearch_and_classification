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
    static bool compchar( const char c1, const char c2 )
    {
        return order[c1] < order[c2];
    }
public:
    StrangeCompare( const string& alphabet)
    {
        char a=' ';
        order.insert({a,1});
        int poz=2;
        int n = alphabet.size();
        for(int i = 0 ; i < n; i++)
        {
            order.insert({alphabet[i],poz++});
        }


    }
    bool operator()( const string& s1, const string& s2 )
    {
        int n=s1.size();
        int m=s2.size();
        int i =0;
        char a,b;
        while(i!=n || i!=m){
            a=s1[i];
            b=s2[i];
            i++;
            if(order[a]!=order[b]){
                return order[a] < order[b];
            }
        }
        return n < m;
    }
};
map<char,int> StrangeCompare::order;

#endif // STRANGECOMPARE_H_INCLUDED
