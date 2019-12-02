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

const int h = 1111;
int n, w,l, r[h];
int x[h], y[h];
pii p[h];

void fill(int x0, int y0, int w, int l, bool okx, bool oky, bool okw, bool okl) {
  if(w<0 || l<0) return;
  int u = 0;
  while(u<n) {
    bool ok = true;
    if(p[u].Y == -1) ok = false;
    if(!okw) {
      if(okx) {
        if(p[u].X > w) ok = false;
      } else {
        if(2*p[u].X > w) ok = false;
      }
    }
    if(!okl) {
      if(oky) {
        if(p[u].X > l) ok = false;
      } else {
        if(2*p[u].X > l) ok = false;
      }
    }
    if(ok) break;
    ++u;
  }
  if(u==n) return;
  int i = p[u].Y;
//  cout << i << ' ' << p[u].X << endl;
  p[u].Y = -1;
  int d = r[i];
  int dx = d, dy = d;
  x[i] = x0;
  if(!okx) {
    x[i] += d;
    dx += d;
  }
  y[i] = y0;
  if(!oky) {
    y[i] += d;
    dy += d;
  }
  if (w <= l) {
    fill(x0, y[i] + d, w, l - dy, okx, false, okw, okl);
    fill(x[i] + d, y0, w - dx, l, false, oky, okw, false);
  } else {
    fill(x[i] + d, y0, w - dx, l, false, oky, okw, okl);
    fill(x0, y[i] + d, w, l - dy, okx, false, false, okl);
  }
}

int main() {
  freopen("b-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("b-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d%d%d", &n, &w, &l);
    REP(i, n) scanf("%d", r+i);
    REP(i, n) p[i] = pii(r[i], i);
    sort(p, p+n);
    reverse(p, p+n);
    fill(0, 0, w, l, true, true, true, true);
    REP(i, n) if(p[i].Y!=-1) cout << "ERROR!!\n";
    printf("Case #%d:", itest);
    REP(i, n) printf(" %d %d", x[i], y[i]);
    printf("\n");
  }
  return 0;
}
