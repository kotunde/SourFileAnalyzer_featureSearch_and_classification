#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool solve()
{
	int n,d;
	scanf("%d",&n);
	vector<pair<int,int> > s(n);
	for (int i=0;i<n;++i)
		scanf("%d%d",&s[i].first,&s[i].second);
	scanf("%d",&d);
	sort(s.begin(),s.end());
	vector<int> bd(n,-1);
	int ml = 0;
	bd[0] = s[0].first;
	for (int i=0;i<n;++i)
		if (bd[i]!=-1)
		{
			for (int j=i+1;j<n;++j)
			{
				if (bd[i]+s[i].first<s[j].first)
					break;
				int x = min(s[j].first-s[i].first,s[j].second);
				bd[j] = max(bd[j],x);
			}
			ml = max(ml,s[i].first+bd[i]);
		}
	return ml>=d;
}

int main(int argc, char* argv[])
{
	if (argc>1)
		freopen(argv[1],"r",stdin);
	else
		freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;++t)
	{
		bool ans = solve();
		printf("Case #%d: ",t+1);
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
