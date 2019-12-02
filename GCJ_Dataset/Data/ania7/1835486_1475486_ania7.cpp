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

#define maxn 1010

bool cmp(pair<pii,int> a, pair<pii,int> b)
{
	int df = a.fi.fi*b.fi.se - a.fi.se*b.fi.fi;
	if(df != 0) return df < 0;
	return a.se < b.se;
}

pair<pii,int> t[maxn];

void test()
{
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &t[i].fi.fi);
	FOR(i,n) scanf("%d", &t[i].fi.se);
	FOR(i,n) t[i].se = i;
	sort(t,t+n,cmp);
	FOR(i,n) printf("%d ", t[i].se);
	printf("\n");
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
