#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include"Person.h"
#include"PersonCompare.h"

using namespace std;

typedef set<string, greater<string> > DecreasingStringSet;
typedef set<Person, PersonCompare > PersonSet;

int main()
{
    DecreasingStringSet p;
//lambda expression
    auto comp = [](string x, string y)
    {
        return x > y;
    };
    set<string,decltype(comp)> s(comp);
    s.insert("korte");
    s.insert("alma");
    s.insert("eper");
    s.insert("szilva");
    cout<<"1---------------------------------\n";
    for( auto& x: s )
    {
        cout<< x<<" ";
    }
    cout<<endl;

    p.insert("korte");
    p.insert("alma");
    p.insert("eper");
    p.insert("szilva");
    for( auto& x: p )
    {
        cout<< x<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------\n";
    PersonSet pers;
    pers.insert(Person("Kiss","Elemer"));
    pers.insert(Person("Kiss","Geza"));
    pers.insert(Person("Nagy","Ella"));
    pers.insert(Person("Aszalos","Lajos"));

    for( auto& x: pers )
    {
        cout<< x;
    }
    cout<<endl;


    return 0;
}
