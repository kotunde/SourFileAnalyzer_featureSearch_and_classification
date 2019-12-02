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

template<class T1, class T2> void smin(T1& a, T2 b) { if (a > b) a = b; }
template<class T1, class T2> void smax(T1& a, T2 b) { if (a < b) a = b; }

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;

const int h = 11111;
int n;
int d[h], l[h], m[h];

int main() {
  freopen("a-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("a-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", d+i, l+i);
    scanf("%d", d+n);
    printf("Case #%d: ", itest);
    CL(m, -1);
    m[0] = 0;
    int u = 1;
    REP(i, n) if (m[i] != -1) {
      smax(m[i], d[i] - l[i]);
      while(u<=n && 2*d[i] - m[i] >= d[u]) m[u++] = d[i];
    }
    printf("%s\n", m[n] != -1 ? "YES" : "NO");
  }
  return 0;
}
