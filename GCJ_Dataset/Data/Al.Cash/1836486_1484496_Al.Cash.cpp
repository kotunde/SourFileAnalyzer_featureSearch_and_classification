#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;

const int h = 555;
int n, a[h];

bool y[2000000];
int s[1<<20];

void outp(int u) {
  REP(i, n) if(u&1<<i) printf("%d ", a[i]);
  printf("\n");
}

int main() {
  freopen("c-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("c-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a+i);
    printf("Case #%d:\n", itest);
    CL(y, 0);
    s[0] = 0;
    pii ans = pii(-1, -1);
    FOR(u, 1, 1<<n) {
      int i = 0;
      while(~u&1<<i) ++i;
      s[u] = s[u-(1<<i)] + a[i];
      if(y[s[u]]) {
        ans.X = u;
        REP(v, u) if(s[v] == s[u]) {
          ans.Y = v;
          break;
        }
        break;
      }
      y[s[u]] = true;
    }
    if(ans.X==-1) printf("Impossible\n");
    else {
      outp(ans.X);
      outp(ans.Y);
    }
  }
  return 0;
}
