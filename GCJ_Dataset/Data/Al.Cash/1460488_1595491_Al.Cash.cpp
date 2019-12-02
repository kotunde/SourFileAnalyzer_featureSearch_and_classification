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

const int N = 111;
int n,s, p, t[N];
int d[N][N];

int main() {
  freopen("b-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("b-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d%d%d", &n, &s, &p);
    REP(i, n) scanf("%d", t+i);
    d[0][0] = 0;
    REP(i, n) {
      bool y0 = t[i] >= 3*p-2;
      bool y1 = t[i] >= 3*p-4;
      REP(j, i+2) {
        d[i+1][j] = -INF;
        if (j<i+1) smax(d[i+1][j], d[i][j] + y0);
        if (j>0 && 2<=t[i] && t[i]<=28) smax(d[i+1][j], d[i][j-1] + y1);
      }
    }
    //REP(i, n+1) { REP(j, i+1) printf("%d ", d[i][j]); printf("\n"); }
    printf("Case #%d: %d\n", itest, d[n][s]);
  }
  return 0;
}
