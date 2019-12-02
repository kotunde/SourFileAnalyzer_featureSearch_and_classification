#ifndef STRANGECOMPARE_H_INCLUDED
#define STRANGECOMPARE_H_INCLUDED
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class StrangeCompare {
private:
    static map<char,int> order;
    static bool compchar (const char c1, const char c2){
        int k1,k2;
        for (auto& a: order){
            if (a.second == c1){k1 = a.first;}
            if (a.second == c2){k2 = a.first;}
        }
        return k1 < k2;
    }
public:
    StrangeCompare(const string& alphabet){
        order.insert(make_pair(' ',0));
        for (unsigned int i = 0; i < alphabet.size(); ++i){
            order.insert(make_pair(alphabet[i],i+1));
        }
    }
    bool operator()(const string& s1, const string& s2){
        return lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end(),compchar);
    }
};

map<char,int> StrangeCompare::order;

#endif // STRANGECOMPARE_H_INCLUDED
