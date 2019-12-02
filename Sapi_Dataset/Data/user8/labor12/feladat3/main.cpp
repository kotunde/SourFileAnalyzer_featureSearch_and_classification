#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include <algorithm>
#include <cctype>

using namespace std;

class StringCompare {
public:
    enum compare_mode { normal, nocase };
    StringCompare( compare_mode mode = normal):mode{mode}{}
    bool operator()(const string& a, const string& b)
    {
        if(mode==nocase){
            return a<b;
        }
        else{
            return mytolower(a)<=mytolower(b);
        }

    }
private:

    compare_mode mode;
    string mytolower(const string& s){
        string ss=s;
        transform(ss.begin(), ss.end(), ss.begin(),::tolower);
        return ss;
    }

};



set<string, StringCompare> s1;//alapértelmezett mód
set<string, StringCompare> s2(StringCompare::nocase);//nocase mód

int main()
{
//lambda expression
    //auto comp = [](Person p1, Person p2) {

    //};

    typedef set<string, StringCompare > Strings;


    //set<string,StringCompare> s;
    //Strings s2;

    set<string, StringCompare> s2(StringCompare::nocase);
    s2.insert("Nagy");
    s2.insert("nagyy");
    s2.insert("Kis");
    s2.insert("KIs");
    for( auto& x: s2 ) {
        cout<< x;
    }

    cout<<endl;
    return 0;
}
