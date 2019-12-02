#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int N = 40;
int n, m;

char board[N][N];

void cleanBoard() {
  
  for (int i = 0; i < n + 2; ++i)
  for (int j = 0; j < m + 2; ++j)
    board[i][j] = 0;
  for (int i = 0; i < n + 2; ++i)
    board[i][0] = board[i][m + 1] = 1;

  for (int j = 0; j < m + 2; ++j)
    board[0][j] = board[n + 1][j] = 1;
}

int cnt;

int bits(long long v) {
  int r = 0;
  while (v) {
    if (v & 1) ++r;
    v /= 2;
  }
  return r;
}
int setStones(long long v) {
  cnt = 0;
  cleanBoard();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if ((board[i][j] = (v & 1))) ++cnt;
      v /= 2;
    }
  return cnt;
}


void setStone(int i, int j) {
  if (board[i][j]) return;
  ++cnt;
  board[i][j] = 1;
  setStone(i + 1, j);
  setStone(i - 1, j);
  setStone(i, j + 1);
  setStone(i, j - 1);
}

int count() {
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    setStone(i, 1);
    setStone(i, m);
  }
  for (int j = 1; j <= m; ++j) {
    setStone(1, j);
    setStone(n, j);
  }
  return cnt;
}
void solve() {
  int k;
  scanf("%d%d%d", &n, &m, &k);
  int ret = min(k, m + m + n + n - 2);
  for (long long i = 0; i < (1LL << (n * m)); ++i) {
    int t = bits(i);
    if (t >= ret) continue;
    setStones(i);
    int c = n * m - count();
    if (c >= k) {
      ret = t;
    }
  }
  printf("%d\n", ret);
}


int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
