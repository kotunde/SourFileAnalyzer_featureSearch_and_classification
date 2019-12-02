#include <iostream>
#include <iterator>
#include <string>
#include <functional>
using namespace std;
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person{
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

class PersonCompare{
public:
    bool operator()(const Person &p1, const Person &p2){
    if(p1.getFirstName() == p2.getFirstName()){
        return p1.getLastName() < p2.getLastName();
    }
    else{
        return p1.getFirstName() < p2.getFirstName();
    }
    }
};

class StringCompare{

public:
    enum compare_mode { normal, nocase };

    StringCompare(compare_mode cm){
        this->cm = cm;
    }

    bool operator()(string s1, string s2){
    if(cm==normal){
        return s1 < s2;
    }

    else if(cm==nocase){

    for (string::const_iterator c1 = s1.begin(), c2 = s2.begin(); c1 != s1.end(); ++c1, ++c2) {
        if (tolower(*c1) != tolower(*c2)) {
            return false;
        }
    }
    return true;
    }
    }
private:
    compare_mode cm;
};


#endif // PERSON_H_INCLUDED
