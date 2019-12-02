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

struct pr
{
	int v, i;
	pr(int ve = 0, int ie = 0)
	{
		i = ie;
		v = ve;
	}

	bool operator < (const pr& p) const
	{
		if(v != p.v)
			return v < p.v;
		return i < p.i;
	}
};

int a[1005];
int init[1005];

int bub(int f, int l, bool s)
{
	int cnt = 0;
	for(int i = f; i < l; i++)
	{
		for(int j = l-1; j > i; j--)
		{
			if(a[j] < a[j-1] && s || a[j] > a[j-1] && !s)
			{
				swap(a[j], a[j-1]);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);


	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
	
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &init[i]);
			//init[i].i = i;
		}

		int mp = 0;
		for(int i = 1; i < n; i++)
		{
			if(init[i] > init[mp])
				mp = i;
		}

		int res = 1000000000;
		for(int p = 0; p < n; p++)
		{
			memcpy(a, init, sizeof(init));
			int tmp = 0;
			if(mp > p)
			{
				for(int i = mp; i > p; i--)
				{
					tmp++;
					swap(a[i], a[i-1]);
				}
			}
			else
			{
				for(int i = mp; i < p; i++)
				{
					tmp++;
					swap(a[i], a[i+1]);
				}
			}
			tmp += bub(0, p, 1);
			tmp += bub(p+1, n, 0);
			res = min(tmp, res);

			//swap(a[p], a[mp]);
			//sort(a, a + p);
			//sort(a + p + 1, a + n);
			//reverse(a + p + 1, a + n);
			//int tmp = 0;
			//for(int i = 0; i < n; i++)
			//	tmp += abs(i - a[i].i);
		}

		printf("%d\n", res);
	}

	return 0;
}