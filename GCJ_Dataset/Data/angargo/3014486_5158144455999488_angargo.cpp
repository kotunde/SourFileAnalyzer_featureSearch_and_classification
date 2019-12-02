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
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;
const ll INF = 1000000000000000000LL;

#define VEI(w,e) ((E[e].u == w) ? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge {
  int u, v;
  ll cap[2], flow;
};

VI d, act;

bool bfs(int s, int t, VVI& adj, vector<Edge>& E) {
  queue<int> Q;
  d = VI(adj.size(), -1);
  d[t] = 0;
  Q.push(t);
  while (not Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < adj[u].size(); ++i) {
      int e = adj[u][i], v = VEI(u, e);
      if (CAP(v, e) > 0 and d[v] == -1) {
        d[v] = d[u] + 1;
        Q.push(v);
      }
    }
  }
  return d[s] >= 0;
}

ll dfs(int u, int t, ll bot, VVI& adj, vector<Edge>& E) {
  if (u == t) return bot;
  for (; act[u] < adj[u].size(); ++act[u]) {
    int e = adj[u][act[u]];
    if (CAP(u, e) > 0 and d[u] == d[VEI(u, e)] + 1) {
      ll inc = dfs(VEI(u, e), t, min(bot, CAP(u, e)), adj, E);
      if (inc) {
        ADD(u, e, inc);
        return inc;
      }
    }
  }
  return 0;
}

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
  for (int i = 0; i < E.size(); ++i) E[i].flow = 0;
  ll flow = 0, bot;
  while (bfs(s, t, adj, E)) {
    act = VI(adj.size(), 0);
    while ((bot = dfs(s, t, INF, adj, E))) flow += bot;
  } 
  return flow;
}

void add_edge(int u, int v, int cap, VVI& adj, vector<Edge>& E) {
  Edge e;
  e.u = u;
  e.v = v;
  e.cap[0] = cap;
  e.cap[1] = 0;
  adj[e.u].push_back(E.size());
  adj[e.v].push_back(E.size());
  E.push_back(e);
}

int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};

int h, w, b;
VPII build;

inline int source() {
  return 2 * h * w;
}

inline int sink() {
  return 2 * h * w + 1;
}

inline int in(int i, int j) {
  return i * w + j;
}

inline int out(int i, int j) {
  return h * w + i * w + j;
}

inline bool ok(int i, int j) {
  return i >= 0 and j >= 0 and i < h and j < w;
}

bool in_build(int i, int j) {
  for (int k = 0; k < b; ++k) {
    if (i >= build[2 * k].first and i <= build[2 * k + 1].first
      and j >= build[2 * k].second and j <= build[2 * k + 1].second) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  int t; cin >> t;
  for (int z = 0; z < t; ++z) {
    cin >> w >> h >> b;
    build = VPII(2 * b);
    for (int i = 0; i < b; ++i) {
      cin >> build[2 * i].second >> build[2 * i].first;
      cin >> build[2 * i + 1].second >> build[2 * i + 1].first;
    }
    VVI adj(2 * h * w + 2);
    vector<Edge> E;
    for (int j = 0; j < w; ++j) {
      add_edge(source(), in(0, j), 1, adj, E);
      add_edge(out(h - 1, j), sink(), 1, adj, E);
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (not in_build(i, j)) add_edge(in(i, j), out(i, j), 1, adj, E);
        // else cout << i << " " << j << " en edificio" << endl;
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d], nj = j + dj[d];
          if (ok(ni, nj)) add_edge(out(i, j), in(ni, nj), 1, adj, E);
        }
      }
    }
    cout << "Case #" << z + 1 << ": " << maxflow(source(), sink(), adj, E) << endl;
  }
}