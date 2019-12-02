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

int a[4][4], b[4][4];

int intersection(int *a, int *b) {
  int c[4];
  sort(a, a+4);
  sort(b, b+4);
  int *e = set_intersection(a, a+4, b, b+4, c);
  if (e == c) return -1;
  if (e > c + 1) return -2;
  return c[0];
}

void solve() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) scanf("%d", a[i] + j);
  scanf("%d", &m);
  for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) scanf("%d", b[i] + j);
  int r = intersection(a[n-1], b[m-1]);
  switch (r) {
    case -2:
      printf("Bad magician!\n");
      break;
    case -1:
      printf("Volunteer cheated!\n");
      break;
    default:
      printf("%d\n", r);
      break;
  }
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
