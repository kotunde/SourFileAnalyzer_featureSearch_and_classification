#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= b; ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,n-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)x.size())
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

#define maxs 1030
#define maxn 10101


int moves, side;

int px[6] = {1,1,0,0,-1,-1}, py[6] = {1,0,1,-1,0,-1};

int c[maxs][maxs];
int t[maxs][maxs];

int q[7];

int mx[maxn], my[maxn];



struct unfi
{
	vector<int> par;
	int N;

	unfi(int NN)
	{
		N=NN;
		par.resize(N);
		FOR(i,N) par[i]=i;
	}

	int fi(int a)
	{
		return par[a] == a ? a : par[a] = fi(par[a]);
	}

	bool un(int a, int b)
	{
		int fa=fi(a);
		int fb=fi(b);
		if(fa!=fb)
		{
			par[fa]=fb;
			return 1;
		}
		return 0;
	}
};

inline bool ok(int x, int y)
{
	if(x < 1 || y < 1 || y > side*2-1 || x > side*2-1)
		return 0;
	if(abs(x-y) >= side)
		return 0;
	return 1;
}

inline bool ok2(int x, int y)
{
	if(x < 0 || y < 0 || y > side*2 || x > side*2)
		return 0;
	if(abs(x-y) > side)
		return 0;
	return 1;
}

void dfs(int x, int y, int col)
{
	c[x][y] = col;
	//printf("[%d %d] -- %d\n", x, y, col);
	FOR(k,6)
	{
		int nx = x+px[k], ny = y+py[k];
		if(ok2(nx,ny) && c[nx][ny] == 0 && t[nx][ny] == 0)
			dfs(nx,ny,col);
	}
}

int detect_ring()
{
	FOR(i,2*side+2) FOR(j,2*side+2) t[i][j] = c[i][j] = 0;
	FOR(i,moves) t[mx[i]][my[i]] = 1;
	int C = 1;
	FOR(i,2*side+1) FOR(j,2*side+1) if(ok2(i,j) && c[i][j]==0 && t[i][j] == 0)
		dfs(i,j,C++);
	int parts = C-1;
	unfi U(C+moves);
	int res = moves+1;
	for(int i = moves-1; i >= 0; i--)
	{
		int prev = parts;
		int x = mx[i], y = my[i];
		t[x][y] = 0;
		c[x][y] = C+i;
		parts++;
		FOR(k,6)
		{
			int nx = x+px[k], ny = y+py[k];
			if(!ok2(nx,ny)) continue;
			if(t[nx][ny]) continue;
			if(U.un(c[x][y], c[nx][ny]))
				parts--;
		}
		if(parts == 1 && prev > 1)
			res = i+1;
	}
	return res;
}

int detect_bridge()
{
	FOR(i,2*side+2) FOR(j,2*side+2) t[i][j] = c[i][j] = 0;
	int S = 2*side;
	unfi U(S*S);
	q[0] = S+1;
	q[1] = S+side;
	q[2] = S*side+1;
	q[3] = S*(2*side-1)+2*side-1;
	q[4] = S*side+2*side-1;
	q[5] = S*(2*side-1)+side;
	FOR(i,moves)
	{
		int x = mx[i], y = my[i];
		t[x][y] = 1;
		FOR(k,6)
		{
			int nx = x+px[k], ny = y+py[k];
			if(t[nx][ny] != 1) continue;
			U.un(nx*S+ny, x*S+y);
		}
		FOR(j,6) FOR(k,j) if(U.fi(q[j]) == U.fi(q[k]))
			return i+1;
	}
	return moves+1;
}

int detect_fork()
{
	FOR(i,2*side+2) FOR(j,2*side+2) t[i][j] = c[i][j] = 0;
	int S = 2*side;
	unfi U(S*S);
	q[0] = S+2;
	for(int i = 3; i < side; i++) U.un(S+2, S+i);
	q[1] = S*2+side+1;
	for(int i = 3; i < side; i++) U.un(S*2+side+1, S*i+side+i-1);
	q[2] = S*2+1;
	for(int i = 3; i < side; i++) U.un(S*2+1, S*i+1);
	q[3] = S*(side+1)+2;
	for(int i = 3; i < side; i++) U.un(S*(side+1)+2, S*(side+i-1)+i);
	q[4] = S*(2*side-1)+2*side-2;
	for(int i = 3; i < side; i++) U.un(S*(2*side-1)+2*side-2, S*(2*side-1)+2*side-i);
	q[5] = S*(2*side-2)+2*side-1;
	for(int i = 3; i < side; i++) U.un(S*(2*side-2)+2*side-1, S*(2*side-i)+2*side-1);
	/*
	printf("\n");
	for(int sum = 4*side; sum >= 0; sum--)
	{
		for(int a = 0; a < sum-(side*3-1); a++) printf("  ");
		for(int a = 0; a < side+1-sum; a++) printf("  " );
		if(sum > side+1 && sum < 3*side-1 && (sum-side)%2 == 0) printf("  ");
		for(int a = 2*side; a >= 0; a--)
		{
			int b = sum - a;
			if(!ok2(a,b)) continue;
			//if(b < 1 || b > 2*side-1) continue;
			//if(abs(a-b) >= side) continue;
			//printf("%02d  ", U.fi(a*S+b));
			printf("%d%d  ", a,b);
		}
		printf("\n");
	}
	*/
	FOR(i,moves)
	{
		int x = mx[i], y = my[i];
		t[x][y] = 1;
		FOR(k,6)
		{
			int nx = x+px[k], ny = y+py[k];
			if(t[nx][ny] != 1) continue;
			U.un(nx*S+ny, x*S+y);
		}
		FOR(a,6) FOR(b,a) if(U.fi(q[a]) == U.fi(q[b])) FOR(c,b) if(U.fi(q[a]) == U.fi(q[c]))
			return i+1;
	}
	return moves+1;

}

void test()
{
	scanf("%d%d", &side, &moves);
	FOR(i,moves) scanf("%d%d", &mx[i], &my[i]);

	int first_ring = detect_ring();
	int first_bridge = detect_bridge();
	int first_fork = detect_fork();

	int first_win = min(first_ring, min(first_bridge, first_fork));

	if(first_win == moves+1)
	{
		printf("none\n");
		return;
	}

	if(first_win == first_ring && first_win == first_bridge && first_win == first_fork)
	{
		printf("bridge-fork-ring in move %d\n", first_win);
		return;
	}

	if(first_win == first_ring && first_win == first_bridge)
	{
		printf("bridge-ring in move %d\n", first_win);
		return;
	}

	if(first_win == first_ring && first_win == first_fork)
	{
		printf("fork-ring in move %d\n", first_win);
		return;
	}

	if(first_win == first_fork && first_win == first_bridge)
	{
		printf("bridge-fork in move %d\n", first_win);
		return;
	}

	if(first_win == first_fork)
	{
		printf("fork in move %d\n", first_win);
		return;
	}

	if(first_win == first_bridge)
	{
		printf("bridge in move %d\n", first_win);
		return;
	}

	if(first_win == first_ring)
	{
		printf("ring in move %d\n", first_win);
		return;
	}
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for(int ii=1;ii<=tt;ii++)
	{
		printf("Case #%d: ", ii);
		test();
	}
	return 0;
}
