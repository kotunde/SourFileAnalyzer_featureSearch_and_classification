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
typedef vector<VVI> VVVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

bool mountain(VI& v) {
  int n = v.size();
  int imax = 0;
  for (int i = 1; i < n; ++i) if (v[i] > v[imax]) imax = i;
  for (int i = imax - 1; i >= 0; --i) if (v[i] >= v[i + 1]) return false;
  for (int i = imax + 1; i < n; ++i) if (v[i] >= v[i - 1]) return false;
  return true;
}

VVVI permutation;
map<VI, int> index;

int bfs(VI& v) {
  int n = v.size();
  VI dist(3628805, -1);
  int iv = index[v];
  queue<int> q;
  q.push(iv);
  dist[iv] = 0;
  while (not q.empty()) {
    int iw = q.front(); q.pop();
    VI w = permutation[n][iw];
    if (mountain(w)) return dist[iw];
    for (int i = 0; i < n - 1; ++i) {
      swap(w[i], w[i + 1]);
      int inext = index[w];
      if (dist[inext] == -1) {
        dist[inext] = dist[iw] + 1;
        q.push(inext);
      }
      swap(w[i], w[i + 1]);
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  permutation = VVVI(11);
  for (int n = 1; n <= 10; ++n) {
    VI p(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    int k = 0;
    do {
      index[p] = k;
      permutation[n].push_back(p);
      ++k;
    } while (next_permutation(p.begin(), p.end()));
  }
  int t; cin >> t;
  for (int z = 0; z < t; ++z) {
    int n; cin >> n;
    VI v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    VI w = v;
    sort(w.begin(), w.end());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (v[i] == w[j]) {
          v[i] = j;
          break;
        }
      }
    }
    cout << "Case #" << z + 1 << ": " << bfs(v) << endl;
  }
}