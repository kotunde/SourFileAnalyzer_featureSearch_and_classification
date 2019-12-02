#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> PII;

struct Block {
  int x1, y1, x2, y2;
};

int dist(Block a, Block b) {
  if (max(a.x1, b.x1) <= min(a.x2, b.x2)) return a.y1 > b.y2 ? a.y1 - b.y2 - 1 :  b.y1 - a.y2 - 1;
  if (max(a.y1, b.y1) <= min(a.y2, b.y2)) return a.x1 > b.x2 ? a.x1 - b.x2 - 1 : b.x1 - a.x2 - 1;
  int diffy = a.y1 > b.y2 ? a.y1 - b.y2 - 1 :  b.y1 - a.y2 - 1;
  int diffx = a.x1 > b.x2 ? a.x1 - b.x2 - 1 : b.x1 - a.x2 - 1;
  return min(diffx, diffy);
}

int dijkstra(vector<vector<int> >& adj, vector<vector<int> >& cost) {
  int n = adj.size();
  vector<int> d(n, 1e9);
  priority_queue<PII> Q;
  Q.push(PII(0, n - 2));
  d[n - 2] = 0;
  while (not Q.empty()) {
    int u = Q.top().second, dist = -Q.top().first; Q.pop();
    if (d[u] != dist) continue;
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
      if (d[v] > d[u] + cost[u][i]) {
        d[v] = d[u] + cost[u][i];
        Q.push(PII(-d[v], v));
      }
    }
  }
  return d.back();
}

int solve() {
  int w, h, b;
  cin >> w >> h >> b;

  vector<Block> v(b);
  for (int i = 0; i < b; ++i) {
    cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
  }

  int n = b + 2;
  vector<vector<int> > adj(n);
  vector<vector<int> > cost(n);

  for (int i = 0; i < b; ++i) {
    adj[b].push_back(i);
    cost[b].push_back(v[i].x1);

    adj[i].push_back(b + 1);
    cost[i].push_back(w - 1 - v[i].x2);
    
    for (int j = 0; j < b; ++j) {
      if (j == i) continue; 
      adj[i].push_back(j);
      assert(dist(v[i], v[j]) >= 0);
      cost[i].push_back(dist(v[i], v[j]));
    }
  }
  adj[n - 2].push_back(n - 1);
  cost[n - 2].push_back(w);
  
  return dijkstra(adj, cost);
}

int main() {
  int casos;
  cin >> casos;
  for (int i = 1; i <= casos; ++i) cout << "Case #" << i << ": " << solve() << endl;
}
