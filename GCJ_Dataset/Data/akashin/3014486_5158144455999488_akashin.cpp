#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

// const char* inputFile = "file.in";
// const char* outputFile = "file.out";

const char* inputFile = "C-small-attempt0.in";
const char* outputFile = "C-small-attempt0.out";

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

namespace maxflow {

#define pb push_back
#define mp make_pair

using namespace std;

const int inf = 1000000000;
const int MAXN = 500009;

struct Edge
{
  Edge(int to, int cap, int rev) : to(to), cap(cap), flow(0), rev(rev)
  {
  }

  int to, cap, flow, rev;
};

vector<Edge> G[MAXN];
int lastEdge[MAXN];
int dist[MAXN];
int T;
int n;

int q[MAXN], hd, tl;

void addEdge(int from, int to, int cap)
{
  G[from].pb(Edge(to, cap, G[to].size()));
  G[to].pb(Edge(from, 0, G[from].size() - 1));
}

int dinic(int v, int minEdge)
{
	// DB(v);
	// DB(minEdge);
  if (!minEdge)
    return 0;

  if (v == T)
    return minEdge;

  for (; lastEdge[v] < G[v].size(); ++lastEdge[v])
  {
    int i = lastEdge[v];
    int to = G[v][i].to;
    int cap = G[v][i].cap;
    int flow = G[v][i].flow;

    if (dist[to] != dist[v] + 1)
      continue;

    if (int f = dinic(to, min(minEdge, cap - flow)))
    {
      G[v][i].flow += f;
      G[to][G[v][i].rev].flow -= f;
      return f;
    }
  }
  return 0;
}

bool buildResidualNetwork(int S)
{
  memset(dist, -1, n * sizeof(int));
  dist[S] = 0;

  hd = tl = 0;
  q[hd++] = S;

  while (tl < hd)
  {
    int v = q[tl++];

    for (int i = 0; i < G[v].size(); ++i)
    {
      int to = G[v][i].to;
      if (G[v][i].cap > G[v][i].flow && dist[to] == -1)
      {
        dist[to] = dist[v] + 1;
        q[hd++] = to;
        if (to == T)
          return true;
      }
    }
  }
  return (dist[T] != -1);
}

long long findMaxFlow(int S)
{
  long long flow = 0;
  while (buildResidualNetwork(S))
  {
    memset(lastEdge, 0, n * sizeof(int));

    while (int f = dinic(S, inf))
      flow += f;
  }
  return flow;
}

};

struct Point {
	Point(int x, int y): x(x), y(y) {}

	Point(): Point(0, 0) {}

	int x, y;
};

struct Building {
	Building(Point p0, Point p1): p0(p0), p1(p1) {}

	Building() {}

	Point p0, p1;
};

class Solver {
public:
	Solver() {
	}

	string solveTest() {
		cin >> W >> H >> b;

		for (int i = 0; i < b; ++i) {
			Point p0, p1;
			cin >> p0.x >> p0.y;
			cin >> p1.x >> p1.y;
			buildings.push_back(Building(p0, p1));
		}

		int ans = stupidSolve();

		return std::to_string(ans);
	}

	int stupidSolve() {
		verticesNumber = 0;
		int S = generateVertex();
		int T = generateVertex();
		buildNetwork(S, T);
		maxflow::n = verticesNumber;
		maxflow::T = T;
		// maxflow::m = edgesNumber;
		int maxFlow = maxflow::findMaxFlow(S);
		for (int i = 0; i < verticesNumber; ++i) {
			maxflow::G[i].clear();
		}
		return maxFlow;
	}

	void buildNetwork(int S, int T) {
		obstacle.resize(W);
		in.resize(W);
		out.resize(W);
		for (int i = 0; i < W; ++i) {
			obstacle[i].resize(H, false);
			in[i].resize(H, -1);
			out[i].resize(H, -1);
		}

		for (int i = 0; i < buildings.size(); ++i) {
			auto b = buildings[i];
			for (int x = b.p0.x; x <= b.p1.x; ++x) {
				for (int y = b.p0.y; y <= b.p1.y; ++y) {
					obstacle[x][y] = true;
				}
			}	
		}

		for (int x = 0; x < W; ++x) {
			// if (good(x, 0)) {
				maxflow::addEdge(S, getIn(x, 0), 1);
			// }
			// DB(getIn(x, 0));
		}
		// maxflow::addEdge(S, generateVertex(), 100);
		// maxflow::addEdge(S, generateVertex(), 100);

		for (int x = 0; x < W; ++x) {
			for (int y = 0; y < H; ++y) {
				if (good(x, y)) {
					maxflow::addEdge(getIn(x, y), getOut(x, y), 1);
					// DB(getIn(x, y));
					// DB(getOut(x, y));
					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (good(nx, ny)) {
							maxflow::addEdge(getOut(x, y), getIn(nx, ny), 1);
						}
					}
				}
			}
		}

		for (int x = 0; x < W; ++x) {
			// if (good(x, H - 1)) {
				// DB(getOut(x, H - 1));
				maxflow::addEdge(getOut(x, H - 1), T, 1);
			// }
		}
	}

	int getIn(int x, int y) {
		if (in[x][y] == -1) {
			in[x][y] = generateVertex();
		}
		return in[x][y];
	}

	int getOut(int x, int y) {
		if (out[x][y] == -1) {
			out[x][y] = generateVertex();
		}
		return out[x][y];
	}

	bool good(int x, int y) {
		if (x < 0 || y < 0 || x >= W || y >= H) {
			return false;
		}
		return !obstacle[x][y];
	}

	int generateVertex() {
		return verticesNumber++;
	}

	int verticesNumber;

	int W, H, b;
	vector<vector<int>> in;
	vector<vector<int>> out;
	vector<vector<char>> obstacle;
	vector<Building> buildings;
};

int main() {
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	for (int testNumber = 1; testNumber <= T; ++testNumber) {
		Solver solver;
		string verdict = solver.solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
