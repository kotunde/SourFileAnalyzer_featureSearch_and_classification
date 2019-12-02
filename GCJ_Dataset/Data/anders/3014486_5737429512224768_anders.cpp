#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int vals[10010];

void solve() {
  int n, cap;
  cin >> n >> cap;
  for (int i=0; i<n; ++i) cin >> vals[i];
  sort(vals, vals+n);
  int ans = 0;
  int mn = 0, mx=n-1;
  while (mn <= mx) {
    if (mn != mx && vals[mx] + vals[mn] <= cap) {
      ++ans;
      --mx;
      ++mn;
    } else {
      ++ans;
      --mx;
    }
  }
  cout << ans << endl;
}

int main() {
  int c;
  cin >> c;
  for (int i=1; i<=c; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

