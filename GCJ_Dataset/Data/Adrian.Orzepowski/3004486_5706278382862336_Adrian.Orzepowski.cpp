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

long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);

  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve() {
  long long p, q;
  scanf("%lld/%lld", &p, &q);
  long long d = gcd(p, q);
  p /= d;
  q /= d;
  int g = 0;
  long long t;
  for (t = 1; t < q; t *= 2) {
    ++g;
  }
  if (t != q || p > q) {
    printf("impossible\n");
  } else {
    while (p > 1) {
      p /= 2;
      --g;
    }
    printf("%d\n", g);
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
