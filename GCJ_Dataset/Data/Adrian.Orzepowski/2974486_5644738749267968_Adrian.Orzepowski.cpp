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

const int N = 1024;
double t1[N], t2[N];
int n;

int war1() {
  int b = 0;
  int e = n-1;
  for (int i = 0; i < n; ++i) {
    if (t1[i] > t2[b]) {
      ++b;
    } else {
      --e;
    }
  }
  return b;
}

int war2() {
  int b = 0;
  int e = n-1;
  for (int i = n-1; i >= 0; --i) {
    if (t1[i] > t2[e]) {
      ++b;
    } else {
      --e;
    }
  }
  return b;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lf", t1 + i);
  for (int i = 0; i < n; ++i) scanf("%lf", t2 + i);
  sort(t1, t1 + n);
  sort(t2, t2 + n);
  printf("%d %d\n", war1(), war2());
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
