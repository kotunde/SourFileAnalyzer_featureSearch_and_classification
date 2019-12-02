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

int a[10005];
bool f[10005];
int n, d;
int ans;

void solve ()
{
	sort(a, a + n);
	memset(f, false, sizeof(f) );

	ans = 0;

	int s = n;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > d / 2)
		{
			s = i;
			break;
		}
	}

	for (int i = s, j = s - 1; i < n; i++)
	{
		while (j >= 0 && (f[j] || a[i] + a[j] > d) )
			j--;

		f[i] = true;
		if (j >= 0)
			f[j] = true;
		ans++;
	}
	int cntDown = 0;
	for (int i = 0; i < s; i++)
		if (!f[i] )
			cntDown++;
	ans += (cntDown + 1) / 2;

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

		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i] );
		}

		// #input

		solve();
	}

	return 0;
}