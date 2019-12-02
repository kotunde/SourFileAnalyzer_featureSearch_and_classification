#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include<string.h>

using namespace std;

class Person
{
    string mfirstName, mlastName;
public:
    Person(string fname="", string lname=""):mfirstName(fname), mlastName(lname) {}
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
};


#endif // PERSON_H_INCLUDED
