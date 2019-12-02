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

double g[2][1005];
int a[2][1005];
int ind[2];
pair < double , int > p[2005];
int n;
int pSize;

int getAnsDeceitfulWar ()
{
	for (int s = 0; s < n; s++)
	{
		bool ok = true;
		for (int i = 0, j = s; j < n; i++, j++)
		{
			if (a[0][j] < a[1][i] )
			{
				ok = false;
				break;
			}
		}

		if (ok)
			return n - s;
	}
	return 0;
}

int getAnsWar ()
{
	int res = 0;
	for (int i = n - 1, j = n - 1; i >= 0; i--)
	{
		if (a[0][i] > a[1][j] )
			res++;
		else
			j--;
	}
	return res;
}

void solve ()
{
	pSize = 0;
	for (int t = 0; t < 2; t++)
	{
		for (int i = 0; i < n; i++)
			p[pSize++] = make_pair(g[t][i], t);
	}
	sort(p, p + pSize);
	for (int i = 0; i < 2; i++)
		ind[i] = 0;
	for (int i = 0; i < pSize; i++)
	{
		int t = p[i].second;
		a[t][ind[t]++] = i;
	}

	int ansDeceitfulWar = getAnsDeceitfulWar();
	int ansWar = getAnsWar();

	printf("%d %d", ansDeceitfulWar, ansWar);
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
		for (int t = 0; t < 2; t++)
		{
			for (int i = 0; i < n; i++)
			{
				scanf("%lf", &g[t][i] );
			}
		}

		// #input

		solve();
	}

	return 0;
}