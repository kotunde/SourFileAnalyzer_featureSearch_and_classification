#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <set>



using namespace std;


string alakit(const string & p)
{
    string s = p;
    transform(s.begin(),s.end(),s.begin(), ::toupper);
    return s;
}


class Person
{
    string mfirstName, mlastName;
    double atlag;
public:
    Person(string fname="", string lname="",double atl = 0):mfirstName(fname), mlastName(lname),atlag(atl) {}
    friend ostream& operator<<( ostream& os, const Person& p)
    {
        os<<p.mfirstName<<" "<<p.mlastName<<endl;
        return os;
    }
    string getFirstName() const
    {
        return mfirstName;
    }
    string getLastName() const
    {
        return mlastName;
    }
    double getAtlag () const
    {
        return atlag;
    }
};


struct PersonCompare
{
    bool operator()( const Person& p1, const Person& p2)
    {
        if (p1.getAtlag() == p2.getAtlag())
        {
            if (p1.getFirstName() == p2.getFirstName())
                return p1.getLastName() < p2.getLastName();
            else return p1.getFirstName() < p2.getFirstName();
        }
        else return p1.getAtlag() > p2.getAtlag();
    }
};



int main()
{
    freopen("be.txt","r",stdin);


    set<Person,PersonCompare> s;

    string a,b;
    double f;

    for (int i = 0 ; i<5 ; i++)
    {
        cin>>a>>b>>f;
        s.insert(Person(a,b,f));
    }

    for (auto & x : s)
    {
        cout<<x;
    }


    return 0;
}
