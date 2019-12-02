//
// Created by attila on 10.12.2018.
//

#ifndef FV_OB_2_PERSON_H
#define FV_OB_2_PERSON_H

#include <string>

using namespace std;

class Person
{
    string mfirstName, mlastName;
public:
    Person(string fname="", string lname=""):mfirstName(fname), mlastName(lname){}
    friend ostream& operator<<( ostream& os, const Person& p){
        os<<p.mfirstName<<" "<<p.mlastName<<endl;
        return os;
    }
    string getFirstName() const{ return mfirstName;}
    string getLastName() const{ return mlastName; }
};

#endif //FV_OB_2_PERSON_H
