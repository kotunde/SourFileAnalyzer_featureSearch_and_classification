#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include "StrangeCompare.h"

using namespace std;

struct chr
{
    char c;
    int i;
};

vector<chr> v;
map<char,int> order;

bool mycmp1(char a,char b)
{
    char aa=toupper(a);
    char bb=toupper(b);
    int ai,bi;
    for (auto& it:v)
    {
        if (it.c==aa)
        {
            ai=it.i;
            break;
        }
    }
    for (auto& it: v)
    {
        if (it.c==bb)
        {
            bi=it.i;
            break;
        }
    }
    return ai<bi;

}
bool mycmp3(char a, char b)
{
    char aa=toupper(a);
    char bb=toupper(b);
    return order[aa]<order[bb];
}

bool mycmp2(const string& a,const string& b)
{
    return lexicographical_compare(a.begin(),a.end(),b.begin(),b.end(),mycmp3);
}
using namespace std;
int main()
{

    //vector<chr> v;
    //map<char,int> order;
//    vector<string> nevek;
//    string line;
//    string abc;
//    ifstream ifs("input.txt");
//    if (ifs.is_open())
//    {
//        ifs >>abc;
//        while(getline(ifs,line))
//        {
//            nevek.push_back(line);
//        }
//    }
//    chr s;
//    s.c=(char)32;
//    s.i=0;
//    order.insert(pair<char,int>((char)32,0));
//
//    for (int i=1; i<=abc.size(); ++i)
//    {
//        chr x;
//        x.c=abc[i];
//        x.i=i;
//        v.push_back(x);
//        //-------------
//        order.insert(pair<char,int>(abc[i],i));
//    }
//    sort(nevek.begin(),nevek.end(),mycmp2);
//    for (auto& it: nevek)
//    {
//        cout << it << endl;
//    }
    ///------------------------------------------------------------
    string line;
    string abc;
    ifstream ifs("input.txt");
    if (ifs.is_open()) {
        ifs >> abc;
    }

    set<string,StrangeCompare> names(StrangeCompare(abc));
    while(getline(ifs,line))
    {
        names.insert(line);
    }
    //set<string,StrangeCompare>::iterator it;
    for (auto& it: names)
    {
        cout << it << endl;
    }

    return 0;
}