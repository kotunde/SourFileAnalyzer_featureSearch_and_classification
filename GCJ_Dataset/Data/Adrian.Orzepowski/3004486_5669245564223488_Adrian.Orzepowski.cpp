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


const long long M = 1000000007;
bool checkString(const string &s) {
  char l['z' + 1];
  for (int i = 'a'; i < 'z'; ++i) l[i] = 0;
  l[(int)s[0]] = 1;
  for (size_t i = 1; i < s.size(); ++i) {
    if (s[i] == s[i-1]) continue;
    if (l[(int)s[i]]) return false;
    l[(int)s[i]] = 1;
  }
  return true;
}

void solve() {
  int n;
  vector<string> cars;
  char buffer[200];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    cars.push_back(buffer);
  }
  int ret = 0;
  int perm[n];
  for (int i = 0; i < n; ++i) perm[i] = i;
  do {
    ostringstream out;
    for (int i = 0; i < n; ++i) {
      out << cars[perm[i]];
    }
    ret += checkString(out.str());
  } while (next_permutation(perm, perm + n));
  ret %= M;
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
