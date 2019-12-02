#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

typedef pair<int, int> PII;

vector<PII> v;
int M[1005][1005];

int n;

int dp(int p, int l) {
  if (p == n) return 0;
  int& ans = M[p][l];
  if (ans == -1) {
    int diffl = abs(v[p].second - l), diffr = abs(v[p].second - (n - 1 - (p - l)));
    ans = min(dp(p + 1, l + 1) + diffl, dp(p + 1, l) + diffr);
  }
  return ans;
}

int solve() {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;  
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  memset(M, -1, sizeof(M));
  return dp(0, 0)/2;
}

bool check(vector<PII>& v) {
  int p = 1;
  while (p < v.size() and v[p - 1].first < v[p].first) ++p;
  while (p < v.size()) {
    if (v[p].first < v[p - 1].first) ++p;
    else return false;
  }
  return true;
}

int cost(vector<PII>& v) {
  int res = 0;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v.size(); ++j) {
      if (v[i].second < v[j].second and i > j) ++res;
    }
  }  
  return res;
}

int solve2() {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;  
    v[i].second = i;
  }
  int res = 1e9;
  sort(v.begin(), v.end());
  do {
    if (check(v)) {
      res = min(res, cost(v));
    }
  } while (next_permutation(v.begin(), v.end())); 
  return res;
}

int main() {
  int casos;
  cin >> casos;
  for (int i = 1; i <= casos; ++i) cout << "Case #" << i << ": " << solve2() << endl;
}
