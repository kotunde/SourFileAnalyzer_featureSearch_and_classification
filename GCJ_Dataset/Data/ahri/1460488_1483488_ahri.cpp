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

int pot10[11];

int probaj (int a, int b, int d) {
//  cout << a << " " << b << " " << d << endl;
  vector<int> sols;
  int ret = 0;
  for (int i=1;i<=d;i++) {
    int nju = a/pot10[i] + pot10[d-i+1]*(a%pot10[i]);
  //cout << nju << endl;
    if (b>=nju && a<nju) {
//      cout << a << " " << nju << endl;
      sols.push_back(nju);
    }
  }
  junik(sols);
  ret = sz(sols);
  return ret;
}

int solve(int a, int b) {
  int sol=0;
  
  int d=0;
  for (int i=0;i<10;i++) if (b>pot10[i]) d=i;
  
  for (int i=a;i<b;i++) {
    sol+=probaj(i, b, d);
  }
  return sol;
}


int main() {

  int n=0;
  int a, b;
  scanf("%d ", &n);
  vector<int> sols;
  
  pot10[0]=1;
  for (int i=1;i<10;i++) pot10[i]=pot10[i-1]*10;
  
  for (int i=0;i<n;i++) {
    scanf("%d %d ", &a, &b);
    if (b<10) { sols.push_back(0); continue; }
    sols.push_back(solve(a,b));
  }
  for (int i=0;i<n;i++) {
    cout << "Case #" << i+1 << ": " << sols[i] << endl;
    }

  return 0;

}