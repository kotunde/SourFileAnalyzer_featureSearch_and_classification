
//Written by Alex H Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

const int maxn=1100;
int mark[maxn];
int p[maxn];
int l[maxn];
int t[maxn];
int n;

void clear() {
  zer(mark);
}

void solve(int cnum) {
  cin>>n;
  FOR (i,n) cin>>l[i];
  FOR (i,n) cin>>p[i];
  FOR (i,n) t[i]=p[i]*l[i];

  cout<<"Case #"<<cnum<<":";

  FOR (i,n) {
	int best=-1;
	int bestj=0;
	FOR (j,n) {
	  if (!mark[j] && t[j]>best) {
		bestj=j; best=t[j];
	  }
	}
	mark[bestj]=1;
	cout<<" "<<bestj;
  }
  cout<<endl;
}

int main() {
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
