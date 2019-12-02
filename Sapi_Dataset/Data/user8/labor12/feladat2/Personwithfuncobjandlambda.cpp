#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
using namespace std;

class Person {
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
    bool operator==(const Person& p){
        if(this->mfirstName == p.getFirstName() && this->mlastName==p.getLastName())
            return true;
        return false;
    }
};

struct PersonCompare
{
    bool operator()(const Person& p1, const Person& p2)
    {
        if(p1.getFirstName()<p2.getFirstName()){
            return true;
        }
        if(p1.getFirstName()==p2.getFirstName() && p1.getLastName()<p2.getLastName()){
            return true;
        }
        return false;
    }
};


int main()
{
//lambda expression
    auto comp = [](Person p1, Person p2) {
        if(p1.getFirstName()<p2.getFirstName()){
            return true;
        }
        if(p1.getFirstName()==p2.getFirstName() && p1.getLastName()<p2.getLastName()){
            return true;
        }
        return false;
    };

    //typedef set<Person, PersonCompare > PersonSet;


    set<Person,decltype(comp)> s(comp);
    //PersonSet s;
    s.insert(Person("Nagy", "Abetu"));
    s.insert(Person("Nagy","Bbetu"));
    s.insert(Person("Kis", "Abetu"));
    s.insert(Person("Kis", "Bbetu"));
    for( auto& x: s ) {
        cout<< x;
    }

    cout<<endl;
    return 0;
}
