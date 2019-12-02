#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <fstream>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int m, n;
VS S;

int buildTrie(int c, int s, int e, VS& T) {
  int res = 0;
  int p = s;
  while (p <= e and T[p].size() <= c) ++p;
  while (p <= e) {
    char curr = T[p][c];
    int st = p;
    while (p + 1 <= e and T[p + 1][c] == curr) ++p;
    res += 1 + buildTrie(c + 1, st, p, T);
    ++p;
  }
  return res;
}

PII result(int i, VI& v) {
  if (i == m) {
    int res = n;
    VVS T(n);
    for (int j = 0; j < m; ++j) T[v[j]].push_back(S[j]);
    for (int j = 0; j < n; ++j) if (T[j].size() == 0) return PII(0, 0);
    for (int j = 0; j < n; ++j) res += buildTrie(0, 0, T[j].size() - 1, T[j]);
    return PII(res, 1);
  }
  PII res(0, 0);
  for (int j = 0; j < n; ++j) {
    v[i] = j;
    PII curr = result(i + 1, v);
    if (curr.first == res.first) res.second += curr.second;
    else if (curr.first > res.first) res = curr;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  int t; cin >> t;
  for (int z = 0; z < t; ++z) {
    cin >> m >> n;
    S = VS(m);
    for (int i = 0; i < m; ++i) cin >> S[i];
    sort(S.begin(), S.end());
    VI v(m);
    PII R = result(0, v);
    cout << "Case #" << z + 1 << ": " << R.first << " " << R.second << endl;
  }
}