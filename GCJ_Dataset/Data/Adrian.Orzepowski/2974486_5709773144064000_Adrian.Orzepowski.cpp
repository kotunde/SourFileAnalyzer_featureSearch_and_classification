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

void solve() {
  double c, f, x;
  scanf("%lf%lf%lf", &c, &f, &x);
  double r = 2;
  double cTime = 0;
  double rTime = x / r;
  for (;;) {
    const double bTime = c / r;
    const double pTime = c / f;
    if (bTime + pTime >= rTime) break;
    r += f;
    rTime = x / r; 
    cTime += bTime;
  }
  printf("%.7lf\n", cTime + rTime);
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
