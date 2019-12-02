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

char o[27] = "yhesocvxduiglbkrztnwjpfmaq";
char a[3][N], b[3][N], c[N];

int main() {
  freopen("a-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("a-small-attempt0.out", "w", stdout);  // -large
  /*REP(i, 26) o[i] = '?';
  o['y'-'a'] = 'a';
  o['e'-'a'] = 'o';
  o['q'-'a'] = 'z';
  REP(i, 3) gets(a[i]);
  REP(i, 3) gets(b[i]);
  REP(i, 3) REP(j, strlen(a[i])) if(a[i][j] != ' ') {
    if (o[a[i][j]-'a'] != '?') {
      if (o[a[i][j]-'a'] != b[i][j]) printf("Error\n");
    } else {
      o[a[i][j]-'a'] = b[i][j];
    }
  }
  printf("%s\n", o);
  return 0;*/
  int itest, ntest;
  for(itest = 1, scanf("%d", &ntest); itest <= ntest; ++itest) {
    gets(c);
    if (strlen(c) == 0) gets(c);
    REP(i, strlen(c)) if (c[i] != ' ') c[i] = o[c[i]-'a'];
    printf("Case #%d: %s\n", itest, c);
  }
  return 0;
}
