#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int> > g;
int t[2000005];
int f[2000005];
int c[2000005];
int sz, st, ed;

int d[500*100*2 + 5];
int p[500*100*2 + 5];
int q[500*100*2 + 5];

int dfs(int v)
{
	if(v == ed)
		return 1;
	for(int& i = p[v]; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(c[to] - f[to] > 0 && d[v] + 1 == d[t[to]])
		{
			if(dfs(t[to]))
			{
				f[to]++;
				f[to^1]--;
				return 1;
			}
		}
	}
	return 0;
}


bool bfs()
{
	memset(d, -1, sizeof(d));
	memset(p, 0, sizeof(p));

	d[st] = 1;
	q[0] = st;
	int cur = 0, qs = 1;
	while(cur < qs)
	{
		int v = q[cur++];
		if(v == ed)
			break;
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if(d[t[to]] == -1 && c[to] - f[to] > 0)
			{
				d[t[to]] = d[v]+1;
				q[qs++] = t[to];
			}
		}
	}
	return d[ed] != -1;
}

int Dinnic()
{
	int sum = 0;
	while(bfs())
	{
		int fl;
		while(fl = dfs(st))
			sum++;
	}
	return sum;
}

int mp[505][105];

int stp[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};

void AddEdge(int fr, int to)
{
	c[sz] = 1;
	f[sz] = 0;
	t[sz] = to;
	g[fr].push_back(sz);
	sz++;

	c[sz] = 0;
	f[sz] = 0;
	t[sz] = fr;
	g[to].push_back(sz);
	sz++;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);


	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
		int n, m, k;
		scanf("%d%d%d", &m, &n, &k);
		sz = 0, st = n*m * 2, ed = n*m * 2+1;
		g.clear();
		g.resize(ed+1);
		memset(f, 0, sizeof(f));
		memset(c, 0, sizeof(c));
		memset(t, 0, sizeof(t));

		int nm = n*m;

		memset(mp, 0, sizeof(mp));
		for(int i = 0; i < k; i++)
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
			if(y1 > y2)
				swap(y1, y2);
			if(x1 > x2)
				swap(x1, x2);
			for(int i = x1; i <= x2; i++)
			{
				for(int j = y1; j <= y2; j++)
					mp[i][j] = 1;
			}
		}

		for(int j = 0; j < m; j++)
		{
			if(!mp[0][j])
				AddEdge(st, j);
			if(!mp[n-1][j])
				AddEdge(nm + (n-1)*m + j, ed);
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(!mp[i][j])
				{
					int fr = nm + i * m + j;
					AddEdge(m * i + j, fr);
					for(int k = 0; k < 4; k++)
					{
						int x = i + stp[k][0];
						int y = j + stp[k][1];
						if(x >= 0 && x < n && y >= 0 && y < m && !mp[x][y])
							AddEdge(fr, x * m + y);
					}
				}
			}
		}

		int res = Dinnic();
		printf("%d\n", res);
	}

	return 0;
}