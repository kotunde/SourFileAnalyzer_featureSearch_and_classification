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

const int h = 222;
int n, s[h], x;

int main() {
  freopen("a-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("a-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d", &n);
    REP(i, n) scanf("%d", s+i);
    x = 0;
    REP(i, n) x += s[i];
    printf("Case #%d:", itest);
    int l = 0, k = 0;
    int y = 0;
    while(1) {
      REP(i, n) if(s[i]==l) ++k;
      if (y + k > x) break;
      y += k;
      ++l;
    }
    double v = double(x-y) / k + l;
    REP(i, n) printf(" %.6lf", 100 * max(0.0, (v - s[i]) / x));
    printf("\n");
  }
  return 0;
}
