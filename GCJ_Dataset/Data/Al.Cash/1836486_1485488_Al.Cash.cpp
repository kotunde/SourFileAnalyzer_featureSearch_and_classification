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
//const double inf = 1e100;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

const int N = 111;
int n,m, h;
int f[N][N], c[N][N];
int a[N][N];

typedef pair<int, pii> pdii;
priority_queue<pdii> q;

bool us[N][N];

void dfs(int i, int j) {
  if(us[i][j]) return;
  us[i][j] = true;
  a[i][j] = h;
  q.push(pdii(h, pii(i, j)));
  REP(d, 4) {
    int ii = i + dx[d];
    int jj = j + dy[d];
    if(ii<0 || ii>=n || jj<0 || jj>=m) continue;
    if(min(c[i][j], c[ii][jj]) >= 50 + max(h, max(f[i][j], f[ii][jj])))
      dfs(ii, jj);
  }
}

void ch(int i, int j, int v) {
  if(a[i][j] < v) {
    a[i][j] = v;
    q.push(pdii(v, pii(i, j)));
  }
}

int main() {
  freopen("b-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("b-small-attempt0.out", "w", stdout);  // -large
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    scanf("%d%d%d", &h, &n, &m);
    REP(i, n) REP(j, m) scanf("%d", &c[i][j]);
    REP(i, n) REP(j, m) scanf("%d", &f[i][j]);
    REP(i, n) REP(j, m) a[i][j] = -INF;
    CL(us, 0);
    dfs(0, 0);
    while(!q.empty()) {
      pdii u = q.top();
      q.pop();
      int i = u.Y.X, j = u.Y.Y;
      if (u.X != a[i][j]) continue;
      REP(d, 4) {
        int ii = i + dx[d];
        int jj = j + dy[d];
        if(ii<0 || ii>=n || jj<0 || jj>=m) continue;
        if(min(c[i][j], c[ii][jj]) < 50 + max(f[i][j], f[ii][jj])) continue;
        int t = min(min(c[i][j], c[ii][jj]) - 50, a[i][j]);
        if(t >= 20 + f[i][j]) ch(ii, jj, t - 10);
        else ch(ii, jj, t - 100);
      }
    }
    printf("Case #%d: %.1lf\n", itest, (h - a[n-1][m-1]) / 10.0);
  }
  return 0;
}
