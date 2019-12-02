#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define IN(_lower,_variable,_higher) (((_lower)<=(_variable)) && ((_variable)<=(_higher)))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORU(v,p,k) for(int v=p;v<k;++v)
#define FORD(v,p,k) for(int v=(p)-1;v>=k;--v)
#define FORLLU(v,p,k) for(LL v=p;v<k;++v)
#define FORLLD(v,p,k) for(LL v=(p)-1;v>=k;--v)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }


string t = "yhesocvxduiglbkrztnwjpfmaq";
string translate(string x) {
  for (int i=0;i<sz(x);i++) if (x[i]!=' ') x[i]=t[x[i]-'a'];
  return x;
}


int main() {

  int n=0;
  char buff[111];
  char outputBuff[200];
  scanf("%d ", &n);
  vector<string> solutions;
  for (int i=0;i<n;i++) {
    scanf("%[^\n] ", buff);    
    sprintf(outputBuff, "Case #%d: %s",i+1, translate(string(buff)).c_str());
    solutions.push_back(string(outputBuff));
  }
  for (int i=0;i<n;i++)
    cout << solutions[i] << endl;

  return 0;

}