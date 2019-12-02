#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

#define maxn 10101

int d[maxn], l[maxn], best[maxn];

bool test()
{
	int n,D;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &d[i], &l[i]);
	scanf("%d", &D);
	for(int i = 0; i < n; i++) best[i] = 0;
	best[0] = d[0];
	set<pair<int,int> > S;
	for(int i = 0; i < n; i++) S.insert(make_pair(-best[i], i));
	while(!S.empty())
	{
		int u = S.begin() -> second;
		S.erase(*S.begin());
		if(d[u] + best[u] >= D) return 1;
		for(int i = u-1; i >= 0 && d[u] - d[i] <= best[u]; i--)
		{
			if(best[i] < d[u] - d[i] && best[i] < l[i])
			{
				S.erase(make_pair(-best[i], i));
				best[i] = min(d[u] - d[i], l[i]);
				S.insert(make_pair(-best[i], i));
			}
		}
		for(int i = u+1; i < n && d[i] - d[u] <= best[u]; i++)
		{
			if(best[i] < d[i] - d[u] && best[i] < l[i])
			{
				S.erase(make_pair(-best[i], i));
				best[i] = min(d[i] - d[u], l[i]);
				S.insert(make_pair(-best[i], i));
			}
		}
	}
	return 0;
}

int main()
{
	int tt;

	scanf("%d", &tt);
	for(int i = 1; i <= tt; i++)
		printf("Case #%d: %s\n", i, test() ? "YES" : "NO");
	return 0;
}
