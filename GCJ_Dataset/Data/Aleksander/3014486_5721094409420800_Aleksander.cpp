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

const int inf = (int) 1e9;

int a[1005];
int gLeft[1005], gRight[1005];
int srt[1005];
int ans[1005][1005];
int n;
int maxVal, maxInd;

bool cmp (int d1, int d2)
{
	return a[d1] > a[d2];
}

void solve ()
{
	if (n == 1)
	{
		printf("0");
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		gLeft[i] = 0;
		for (int j = 0; j < i; j++)
			if (a[j] > a[i] )
				gLeft[i]++;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		gRight[i] = 0;
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[i] )
				gRight[i]++;
	}

	for (int i = 0; i < n; i++)
		srt[i] = i;
	sort(srt, srt + n, cmp);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = inf;

	ans[0][0] = 0;
	for (int i = 1; i < n; i++)
	{
		int cur = srt[i];

		for (int j = 0; j < i; j++)
		{
			ans[i][j + 1] = min(ans[i][j + 1], ans[i - 1][j] + gLeft[cur] );
			ans[i][j] = min(ans[i][j], ans[i - 1][j] + gRight[cur] );
		}
	}

	int res = inf;
	for (int i = 0; i < n; i++)
	{
		res = min(res, ans[n - 1][i] );
	}
	printf("%d", res);
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

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i] );
		}

		// #input

		solve();
	}

	return 0;
}