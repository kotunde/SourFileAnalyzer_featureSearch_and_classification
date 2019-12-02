#ifndef STRINGCOMPARE_H_INCLUDED
#define STRINGCOMPARE_H_INCLUDED
#include <string>

using namespace std;

class StringCompare{
public:
    enum compare_mode {normal, nocase };
    StringCompare(compare_mode mode): mode(mode) {};
    operator() (string a, string b){return (a < b);}
private:
    compare_mode mode = normal;
};

#endif // STRINGCOMPARE_H_INCLUDED
