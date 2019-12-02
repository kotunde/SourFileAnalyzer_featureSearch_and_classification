#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
#include "StringCompare.h"
using namespace std;

int main()
{
   string s1="alma";
   string s2="Korte";
   string s3="Ananasz";
   set<string, StringCompare> s;
   s.insert(s1);
   s.insert(s2);
   s.insert(s3);
    for(auto& x:s)
    {
        cout<<x<<" "<<endl;
    }
    return 0;
}
