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

int score[101];
char buff[100];

int fair[31][11];
int surp[31][11];

void precalc() {
  memset(fair, 0, sizeof(fair));
  memset(surp, 0, sizeof(surp));
  

  for (int i=0;i<=10;i++)
    for (int j=i;j<=10 && j<=i+2;j++)
      for (int k=j;k<=10 && k<=i+2;k++) {
        if (k-i==2) for (int x=0;x<=k;x++) surp[i+j+k][x]=1;
        if (k-i<2) for (int x=0;x<=k;x++) fair[i+j+k][x]=1;
      }
}


int main() {

  

  int T=0;
  scanf("%d ", &T);
  int N, S, p;
  int cando[3];
  vector<string> sols;
  precalc();  
  for (int caseNum=1;caseNum<=T;caseNum++) {
    scanf ("%d %d %d ", &N, &S, &p);
    memset(score, 0, sizeof(score));
    memset(cando, 0, sizeof(cando));
    
    int sol=0;
    
    int fairs = 0, surps = 0, both =0, canmake = 0;
    
    
    for (int i=0;i<N;i++) {
      scanf("%d ", &score[i]);
      if(fair[score[i]][p] && surp[score[i]][p]) both++;
      if(fair[score[i]][p] && !surp[score[i]][p]) fairs++;
      if(!fair[score[i]][p] && surp[score[i]][p]) surps++;
      if (!fair[score[i]][p] && !surp[score[i]][p]) for (int j=0;j<=10;j++) if (surp[score[i]][j]) { canmake++; break; }
    }
   
    
    
    sol = both + fairs + surps;
    if (S<surps) {
      int diff = surps-S;
      sol -= diff;
    }
    if (S>surps+both + canmake) sol = -1;
    
   
    sprintf(buff, "Case #%d: %d", caseNum, sol);
    sols.push_back(string(buff));
  
  }
  
  for (int i=0;i<T;i++)
    cout << sols[i] << endl;
  

  return 0;

}