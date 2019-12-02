#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include "person.h"

using namespace std;

int main()
{

typedef set<string, greater<string> > DecreasingStringSet;
DecreasingStringSet s;

 s.insert("korte");
 s.insert("alma");
 s.insert("eper");
 s.insert("szilva");
 for( auto& x: s ){
 cout<< x<<" ";
 }
 cout<<endl;

 typedef set<Person, PersonCompare > Persons;
 Persons P;

 P.insert(Person("Pal", "Istvan"));
 P.insert(Person("Feher", "Julia"));
 P.insert(Person("Gergely", "Albert"));
 P.insert(Person("Bertalan", "Agnes"));
 P.insert(Person("Balint", "Adam"));
 P.insert(Person("Kalith", "Goreny"));
  for( auto& v: P ){
 cout<< v<<" ";
 }
 cout<<endl;

 set<string, StringCompare> s1;//alapértelmezett mód
 set<string, StringCompare> s2(StringCompare::nocase);//nocase mód
 return 0;
}
