#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
using namespace std;
typedef set<string, greater<string> > DecreasingStringSet;
int main()
{
 //lambda expression
 auto comp = [](string x, string y){ return x > y; };
 set<string,decltype(comp)> s(comp);
 s.insert("korte");
 s.insert("alma");
 s.insert("eper");
 s.insert("szilva");
 for( auto& x: s ){
 cout<< x<<" ";
 }
 cout<<endl;
 //fuggveny objectum
 set<string, greater<string> > a;
 a.insert("korte");
 a.insert("alma");
 a.insert("eper");
 a.insert("szilva");
 for( auto& x: a ){
 cout<< x<<" ";
 }
 return 0;
}
