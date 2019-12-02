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

int a,b;

int main() {
  freopen("c-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("c-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d%d", &a, &b);
    int ans = 0;
    FOR(n, a, b-1) {
      int x = n, t = 1, p = 0;
      while (10*t <= x) t *= 10, ++p;
      vi y;
      REP(i, p) {
        int d = x%10;
        x = t*d + x/10;
        if (n<x && x<=b) y.pb(x);
      }
      sort(all(y));
      REP(i, sz(y)) if (i==0 || y[i]!=y[i-1]) ++ans;
    }
    printf("Case #%d: %d\n", itest, ans);
  }
  return 0;
}
