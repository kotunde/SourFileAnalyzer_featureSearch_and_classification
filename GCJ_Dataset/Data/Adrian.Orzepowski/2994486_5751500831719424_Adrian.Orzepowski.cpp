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
  int n;
  scanf("%d", &n);
  char s[n][200];
  int is[n];
  int cnt[n];
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    is[i] = 0;
    cnt[i] = 0;
  }
  int ret = 0;
  for (;;) {
    int finish = 0;
    for (int i = 0; i < n; ++i) {
      if (!s[i][is[i]]) ++finish;
    }
    if (finish) {
      if (finish < n) {
        ret = -1;
      } 
      break;
    }

    for (int i = 0; i < n; ++i) {
      cnt[i] = 1;
      for (++is[i]; s[i][is[i]] == s[i][is[i]-1]; ++is[i]) {
        ++cnt[i];
      }
      if (s[i][is[i] - 1] != s[0][is[0]-1]) {
         ret = -1;
         break;
      }
    }
    if (ret == -1) {
      break;
    }
    nth_element(cnt, cnt + n/2, cnt + n);
    for (int i = 0; i < n; ++i) {
      ret += abs(cnt[i] - cnt[n/2]);
    }
  }
  if (ret < 0) {
    printf("Fegla Won\n");
  } else {
    printf("%d\n", ret);
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
