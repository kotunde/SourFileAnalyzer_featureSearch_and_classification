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

int abs(int x) { return x<0 ? -x : x; }
int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }

const int N = 33;

int w,h, d;
char a[N][N];

int iX, jX;
int k;
int ans;

void go(int x, int y, int dx, int dy) {
  //printf("%d %d:\n", x*dx, y*dy);
  int i = iX, j = jX;
  int zx = 1, zy = 1;
  int c = 1;
  while (2*k*x >= 2*zx-1 || 2*k*y >= 2*zy-1) {
    int v = y * (2*zx-1) - x * (2*zy-1);
    if (v == 0) {
      if (a[i+dx][j+dy] != '#') {
        i += dx;
        j += dy;
      } else {
        if (a[i+dx][j] != '#' && a[i][j+dy] != '#') return;
        if (a[i+dx][j] != '#') {
          if (a[i][j+dy] != '#') j += dy;
          else dy = -dy;
          i += dx;
        } else {
          if (a[i][j+dy] != '#') j += dy;
          else dy = -dy;
          dx = -dx;
        }
      }
      ++zx;
      ++zy;
    } else {
      if (v < 0) {
        if (a[i+dx][j] != '#') i += dx;
        else dx = -dx;
        ++zx;
      } else {
        if (a[i][j+dy] != '#') j += dy;
        else dy = -dy;
        ++zy;
      }
    }
    //printf("%d %d\n", i, j);
    if (2*c*x <= 2*zx-1 && 2*c*y <= 2*zy-1) {
      if (i == iX && j == jX) {
        ++ans;
        //printf("!\n");
        return;
      }
      ++c;
    }
  }
}

int main() {
  freopen("d-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("d-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d%d%d", &h, &w, &d);
    REP(i, h) scanf("%s", a[i]);
    iX = 0;
    jX = 0;
    REP(i, h) REP(j, w) if (a[i][j] == 'X') {
      iX = i;
      jX = j;
      break;
    }
    ans = 0;
    REP(x, d+1) REP(y, d+1) if (x+y > 0) {
      int l2 = x*x + y*y;
      k = (d*d) / l2;
      k = floor(sqrt(double(k)) + 1e-9);
      if (k < 1 || gcd(x, y) != 1) continue;
      go(x, y, 1, 1);
      if (x != 0) go(x, y, -1, 1);
      if (y != 0) go(x, y, 1, -1);
      if (x != 0 && y != 0) go(x, y, -1, -1);
    }
    printf("Case #%d: %d\n", itest, ans);
  }
  return 0;
}
