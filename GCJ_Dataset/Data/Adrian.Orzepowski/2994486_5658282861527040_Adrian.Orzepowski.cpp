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

void solveEasy() {
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  int ret = 0;
  for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) {
    if ((i & j) < k) {
      ++ret;
    }
  }
  printf("%d\n", ret);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    printf("Case #%d: ", tc);
    solveEasy();
  }
  return 0;
}
