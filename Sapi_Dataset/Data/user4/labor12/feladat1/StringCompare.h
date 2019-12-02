#ifndef STRINGCOMPARE_H_INCLUDED
#define STRINGCOMPARE_H_INCLUDED
#include<algorithm>
#include<cctype>
using namespace std;

class StringCompare
{
public:
    enum compare_mode { normal, nocase };
private:
    StringCompare(compare_mode)
    {

    }


    string upper(const string& s)
    {
        string ss=s;
        transform(ss.begin(),ss.end(),ss.begin(), ::tolower());
        return ss;
    }
};

#endif // STRINGCOMPARE_H_INCLUDED
