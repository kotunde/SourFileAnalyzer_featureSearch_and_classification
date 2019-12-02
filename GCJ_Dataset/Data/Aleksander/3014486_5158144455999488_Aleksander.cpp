#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct Edge
{
	int to, f, u, rev;

	Edge () {}
	Edge (int to, int f, int u, int rev) : to(to), f(f), u(u), rev(rev) {}
};

vector < Edge > e[500005];
int g[505][505];
int w, h, b;
int vertices;
int st, fin;

bool f[500005];
int p[500005], pInd[500005], q[500005];

void addEdge (int v1, int v2, int u)
{
	e[v1].push_back(Edge(v2, 0, u, e[v2].size() ) );
	e[v2].push_back(Edge(v1, 0, 0, e[v1].size() - 1) );
}

void clearGraph ()
{
	for (int i = 0; i < vertices; i++)
		e[i].clear();
}

bool inField (int x, int y)
{
	return x > -1 && y > -1 && x < w && y < h;
}

int getVInd (int x, int y)
{
	return 2 * (y * w + x);
}

int getFlow ()
{
	int res = 0;

	while (true)
	{
		memset(f, false, sizeof(f) );
		q[0] = st;
		f[st] = true;
		for (int cur = 0, size = 1; cur < size; cur++)
		{
			int v = q[cur];

			for (int i = 0; i < e[v].size(); i++)
			{
				int to = e[v][i].to;
				if (!f[to] && e[v][i].f < e[v][i].u)
				{
					f[to] = true;
					p[to] = v;
					pInd[to] = i;
					q[size++] = to;
				}
			}
		}

		if (!f[fin] )
			break;
		res++;

		for (int v = fin; v != st; v = p[v] )
		{
			int pv = p[v];
			int pvInd = pInd[v];
			e[pv][pvInd].f++;
			e[v][e[pv][pvInd].rev].f--;
		}
	}

	return res;
}

void solve ()
{
	vertices = w * h * 2 + 2;
	st = vertices - 2; fin = vertices - 1;
	clearGraph();

	for (int x = 0; x < w; x++)
	{
		if (g[0][x] == 0)
		{
			int ind = getVInd(x, 0);
			addEdge(st, ind, 1);
		}
	}
	for (int x = 0; x < w; x++)
	{
		if (g[h - 1][x] == 0)
		{
			int ind = getVInd(x, h - 1);
			addEdge(ind + 1, fin, 1);
		}
	}
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if (g[y][x] == 1)
				continue;

			int ind = getVInd(x, y);

			for (int k = 0; k < 4; k++)
			{
				int xn = x + dx[k];
				int yn = y + dy[k];

				if (inField(xn, yn) && g[yn][xn] == 0)
				{
					int nInd = getVInd(xn, yn);
					addEdge(ind + 1, nInd, 1);
				}
			}
		}
	}
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if (g[y][x] == 1)
				continue;

			int ind = getVInd(x, y);
			addEdge(ind, ind + 1, 1);
		}
	}

	int ans = getFlow();
	printf("%d", ans);
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test_amount, test_num;

	scanf("%d\n", &test_amount);
	for (test_num = 0; test_num < test_amount; test_num++)
	{
		if (test_num)
			printf("\n");

		printf("Case #%d: ", test_num + 1);

		// input

		scanf("%d%d%d", &w, &h, &b);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				g[i][j] = 0;
		for (int i = 0; i < b; i++)
		{
			int xa, ya, xb, yb;
			scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
			for (int x = xa; x <= xb; x++)
				for (int y = ya; y <= yb; y++)
					g[y][x] = 1;
		}

		// #input

		solve();
	}

	return 0;
}