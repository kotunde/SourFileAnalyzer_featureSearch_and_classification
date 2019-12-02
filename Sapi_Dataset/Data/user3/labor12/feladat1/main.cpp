#include <iostream>
#include <functional>
#include <set>
#include <algorithm>
#include "Person.h"

using namespace std;

typedef set<string, greater<string> > DecreasingStringSet;

class StringCompare{
    public:
        enum compare_mode { normal, nocase };
        StringCompare(compare_mode mode=normal): mode(mode){};
        bool operator()(const string& s1, const string& s2){
            if(this->mode==normal){
                return s1<s2;
            }
            if(this->mode==nocase){
                string s11=s1, s22=s2;
                transform(s11.begin(), s11.end(),s11.begin(),::tolower);
                transform(s22.begin(), s22.end(),s22.begin(),::tolower);
                return s11<s22;
            }
        };

    private:
        compare_mode mode;
};

int main()
{
//  1. feladat *****************************************************************
    cout<<"1. feladat*******************************************************\n\n";
    DecreasingStringSet h;
    h.insert("korte");
    h.insert("alma");
    h.insert("eper");
    h.insert("szilva");
    for( auto& x: h )
    {
        cout<< x<<" ";
    }
    cout<<endl;

    //lambda expression
    cout<<"\nlambda:\n";
    auto comp = [](string x, string y)
    {
        return x > y;
    };
    set<string,decltype(comp)> s(comp);
    s.insert("korte");
    s.insert("alma");
    s.insert("eper");
    s.insert("szilva");
    for( auto& x: s )
    {
        cout<< x<<" ";
    }
    cout<<"\n\n\n";


    //  2. feladat *****************************************************************
    cout<<"2. feladat*******************************************************\n\n";
    set<Person, PersonCompare> p;
    Person p1("Peter", "Smith");
    Person p2("Jack", "Sparrow");
    Person p3("Anne", "Cooper");
    Person p4("John", "Doe");
    Person p5("Jane", "Watson");
    p.insert(p1);
    p.insert(p2);
    p.insert(p3);
    p.insert(p4);
    p.insert(p5);
    for( auto& x: p )
    {
        cout<< x;
    }
    cout<<endl;

    cout<<"lambda:\n";
    auto compP = [](Person p1, Person p2)
    {
        if(p1.getLastName()==p2.getLastName()){
                return p1.getFirstName() < p2.getFirstName();
            }
        return p1.getLastName() < p2.getLastName();
    };
    set<Person,decltype(compP)> P(compP);
    P.insert(p1);
    P.insert(p2);
    P.insert(p3);
    P.insert(p4);
    P.insert(p5);
    for( auto& x: P )
    {
        cout<< x;
    }
    cout<<endl;



    //  3. feladat *****************************************************************
    cout<<"\n3. feladat*******************************************************\n\n";
    set<string, StringCompare> s1;//alapértelmezett mód
    set<string, StringCompare> s2(StringCompare::nocase);//nocase mód
    s1.insert("Korte");
    s1.insert("alma");
    s1.insert("Eper");
    s1.insert("szilva");
    s2.insert("Korte");
    s2.insert("alma");
    s2.insert("Eper");
    s2.insert("szilva");
    cout<<"normal:\n\t";
    for( auto& x: s1 )
    {
        cout<< x<<" ";
    }
    cout<<endl;
    cout<<"nocase:\n\t";
    for( auto& x: s2 )
    {
        cout<< x<<" ";
    }
    cout<<endl;
    return 0;
}
