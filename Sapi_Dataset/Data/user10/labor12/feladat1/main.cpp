#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include <algorithm>
#include <cctype>
using namespace std;

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
    bool operator()(const Person& a, const Person& b){
        return a.getLastName()<b.getLastName();
    };
};
class StringCompare{
public:
    enum compare_mode { normal, nocase };
    StringCompare(compare_mode mode=compare_mode::normal) : mode(mode){}
    bool operator()(string a, string b){
        if(mode==compare_mode::normal) return a<b;
        string aa=a,bb=b;
        transform(a.begin(),a.end(),aa.begin(), ::tolower ); /// VAGY [](unsigned char c){return std::tolower(c);}
        transform(b.begin(),b.end(),bb.begin(), ::tolower );
        return aa<bb;
    }
private:
    compare_mode mode;
};
int main(){
    set<string, StringCompare> s1;//alapértelmezett mód
    set<string, StringCompare> s2(StringCompare::nocase);//nocase mód
    s1.insert("korte");
    s1.insert("alma");
    s1.insert("Eper");
    s1.insert("Szilva");
    for( auto& x: s1 ) cout<< x<<" ";
    cout<<endl;
    s2.insert("korte");
    s2.insert("alma");
    s2.insert("Eper");
    s2.insert("Szilva");
    for( auto& x: s2 ) cout<< x<<" ";
    cout<<endl;
    return 0;
}
int main2(){
    set<Person,PersonCompare> p;
    p.insert( Person( "Ors", "Kezdi") );
    p.insert( Person( "Csongor", "Czecze") );
    p.insert( Person( "Adam", "Nemeth") );
    p.insert( Person( "Istvan", "Bartos Cs.") );
    for( auto& x:p ) cout<<x;
    return 0;
}

int main1(){
    set<string,greater<string>> s;
    s.insert("korte");
    s.insert("alma");
    s.insert("eper");
    s.insert("szilva");
    for( auto& x: s ){
        cout<< x<<" ";
    }
    cout<<endl;
    return 0;
}
