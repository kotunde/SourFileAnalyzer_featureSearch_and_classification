#ifndef STRANGECOMPARE_H_INCLUDED
#define STRANGECOMPARE_H_INCLUDED

#include <map>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class StrangeCompare{
    private:
        static map<char, int> order;//Karakterek sorrendje
    public:
        StrangeCompare( const string& alphabet){
            istringstream iss(alphabet);
            char c;
            int i=1;
            order[' ']=0;
            while(iss>>c){
                this->order.insert(make_pair(c,i));
                i++;
            }
        }
        bool operator()( const string& s1, const string& s2 ){
            return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), compchar);
        }
        static bool compchar( const char c1, const char c2 ){
            return order[c1] < order[c2];
        }
};

map<char,int> StrangeCompare::order;

#endif // STRANGECOMPARE_H_INCLUDED
