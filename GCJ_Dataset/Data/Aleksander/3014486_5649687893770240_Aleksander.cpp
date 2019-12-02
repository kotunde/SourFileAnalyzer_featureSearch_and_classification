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

string s[10];
int g[5][10];
int gSize[5];
int n, m;

char buf[15];

int ans;
int ansCnt;

int checkGroup (int ind)
{
	int res = 1;

	for (int i = 0; i < gSize[ind]; i++)
	{
		int cur = g[ind][i];

		res += (int) s[cur].size();

		int maxComPrefix = 0;
		for (int j = 0; j < i; j++)
		{
			int compCur = g[ind][j];
			int curComPrefix = 0;
			for (int k = 0; k < s[cur].size() && k < s[compCur].size(); k++)
			{
				if (s[cur][k] != s[compCur][k] )
					break;
				curComPrefix++;
			}
			maxComPrefix = max(maxComPrefix, curComPrefix);
		}
		res -= maxComPrefix;
	}

	return res;
}

void checkRes ()
{
	int curRes = 0;
	for (int i = 0; i < n; i++)
	{
		curRes += checkGroup(i);
	}

	if (curRes > ans)
	{
		ans = curRes;
		ansCnt = 1;
	}else if (curRes == ans)
	{
		ansCnt++;
	}
}

void getAns (int ind, int emptyGroups)
{
	if (ind == m)
	{
		checkRes();
		return ;
	}

	int sRem = m - ind;
	for (int i = 0; i < n; i++)
	{
		if (sRem > emptyGroups || gSize[i] == 0)
		{
			int emptyGroupsNew = emptyGroups;
			if (gSize[i] == 0)
				emptyGroupsNew--;

			g[i][gSize[i]++] = ind;
			getAns(ind + 1, emptyGroupsNew);
			gSize[i]--;
		}
	}
}

void solve ()
{
	for (int i = 0; i < n; i++)
		gSize[i] = 0;

	ans = -1;
	ansCnt = -1;

	getAns(0, n);

	printf("%d %d", ans, ansCnt);
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

		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; i++)
		{
			scanf("%s", buf);
			s[i] = string(buf);
		}

		// #input

		solve();
	}

	return 0;
}