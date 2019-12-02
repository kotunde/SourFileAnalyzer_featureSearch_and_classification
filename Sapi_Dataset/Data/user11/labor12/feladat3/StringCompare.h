#ifndef STRINGCOMPARE_H_INCLUDED
#define STRINGCOMPARE_H_INCLUDED
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
class StringCompare
{

public:
    enum compare_mode { normal, nocase };

    StringCompare(compare_mode mode = normal):mode(mode){}
    bool operator()(const string &, const string&);
private:
        compare_mode mode;
};

bool StringCompare::operator()( const string & a, const string& b)
{
    string a1=a,b1=b;
    transform(a1.begin(),a1.end(),a1.begin(),::tolower);
    transform(b1.begin(),b1.end(),b1.begin(),::tolower);
    return a1<b1;
}
#endif // STRINGCOMPARE_H_INCLUDED
