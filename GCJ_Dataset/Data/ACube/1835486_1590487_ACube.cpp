#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

const int MAXM = 100000;

int test_num, case_number;
typedef pair <int, int> pint;

#define x first
#define y second
#define gout case_number++, printf("Case #%d: ",case_number), cout

string ans[] = {"bridge in move ", "fork in move ", "bridge-fork in move ", "ring in move ", "bridge-ring in move ", "fork-ring in move ", "bridge-fork-ring in move "};

int bits[1<<13], good[1<<13];
int s, m;
int msk[MAXM];
pint u;
pint cor[MAXM];
vector <pint> corn;

int ver;
int p[MAXM];

int getmsk(const pint &u)
{
	for (int i = 0; i < SIZE(corn); i++)
		if (corn[i] == u) return 1<<i;

	if (u.x >= 2*s || u.y >= 2*s) return -1;
	if (u.x < 1 || u.y < 1) return -1;

	if (u.x <= s)
	{
		if (u.y >= u.x+s) return -1;
	}
	else
	{
		if (u.y <= u.x-s) return -1;
	}

	if (u.x == 1) return (1<<0)<<6;
	if (u.y == 1) return (1<<1)<<6;
	if (u.x == 2*s-1) return (1<<2)<<6;
	if (u.y == 2*s-1) return (1<<3)<<6;
	if (u.x-s == u.y-1) return (1<<4)<<6;
	if (u.y-s == u.x-1) return (1<<5)<<6;

	return 0;
}

map <pint, int> dist, dist2;
pair <pint, int> q[2000];
bool isring[MAXM];

int getp(int u)
{
 	return u==p[u]?u:p[u]=getp(p[u]);
}

void join(int u, int v)
{
 	v = getp(v); u = getp(u);
 	if (u == v) return;
 	if (rand()&1)
 		p[u] = v,
 		msk[v] |= msk[u];
 	else
 		p[v] = u,
 		msk[u] |= msk[v];
}

bool iscon(const pint &a, const pint &b)
{
	int dx = a.x - b.x, dy = a.y - b.y;
	if (!dx && !dy) return 0;
	if (dx && dy && dx!=dy) return 0;
	if (max(abs(dx), abs(dy)) != 1) return 0;
	return 1;
}

void main2()
{
	scanf("%d%d", &s, &m);

	corn.clear();
	corn.PB(MP(1, 1));
	corn.PB(MP(2*s-1, 2*s-1));
	corn.PB(MP(1, s));
	corn.PB(MP(s, 1));
	corn.PB(MP(2*s-1, s));
	corn.PB(MP(s, 2*s-1));

	dist.clear();
	dist2.clear();
	ver = 0;
	for (int it = 0; it < m; it++)
	{
		scanf("%d%d", &u.x, &u.y);
		cor[it] = u;

		int whomsk = getmsk(u), v;

		if (!dist.count(u)) p[ver] = ver, msk[ver] = whomsk, dist[u] = ver++;
	}

	for (int it = 0; it < m; it++)
	{
		u = cor[it];

		int whomsk = getmsk(u), v;

		v = dist[u];

		if (!dist2.count(u)) dist2[u] = 1;

		int cur = 0, t = 0;
		pint val;

		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1, to; dy <= 1; dy++)
			{
				val = u;
				val.x += dx; val.y += dy;

				if (getmsk(val) == -1) continue;

				if (!iscon(val, u)) continue;

				if (!dist.count(val))
					to = -1;
				else
					to = dist[val];

				q[t++] = MP(val, to);
			}

//		cerr << "Here v = " << v << endl;
//		cerr << "p[v] = " << getp(v) << " " << msk[getp(v)] << endl;

		for (int i = 0; i < t; i++)
			if (q[i].second == -1)
			for (int j = 0; j < t; j++)
				if (q[j].second != -1 && iscon(q[i].first, q[j].first))
				for (int k = j+1; k < t; k++)
					if (q[k].second != -1 && getp(q[j].second)==getp(q[k].second) && iscon(q[i].first, q[k].first))
					{
					 	cur |= 1<<2;
					 	break;
					}

		for (int i = 0; i < t; i++)
			if (q[i].second!=-1 && dist2.count(q[i].first))
				join(v, q[i].second);

		cur |= good[msk[getp(v)]];

		if (cur)
		{
			gout << ans[cur-1] << it+1 << endl;
			return;
		}
	}
	gout << "none\n";
}

int main()
{
	// [bridge, fork, ring]
	scanf("%d", &test_num);

	for (int i = 0; i < (1<<13); i++)
		for (int j = i; j; j >>=1)
			bits[i] += j&1;

	for (int i = 0; i < (1<<13); i++)
	{
		good[i] = 0;
	 	if (bits[i&63] >= 2) good[i] |= 1<<0;
		if (bits[i>>6] >= 3) good[i] |= 1<<1;
	}

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
