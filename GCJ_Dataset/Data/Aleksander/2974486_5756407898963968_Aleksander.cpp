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

int g[2][4][4];
int r[2];
int cnt[20];

void BAD ()
{
	printf("Bad magician!");
}
void CHEAT ()
{
	printf("Volunteer cheated!");
}

void solve ()
{
	memset(cnt, 0, sizeof(cnt) );
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			cnt[g[i][r[i] ][j] ]++;

	int ansCnt = 0;
	int ans = -1;
	for (int i = 1; i <= 16; i++)
	{
		if (cnt[i] == 2)
		{
			ansCnt++;
			ans = i;
		}
	}

	if (ansCnt == 0)
	{
		CHEAT();
		return ;
	}
	if (ansCnt > 1)
	{
		BAD();
		return ;
	}
	printf("%d", ans);
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test, t;

	scanf("%d\n", &test);
	for (t = 0; t < test; t++)
	{
		if (t)
			printf("\n");

		printf("Case #%d: ", t + 1);

		// input

		for (int i = 0; i < 2; i++)
		{
			scanf("%d", &r[i] );
			r[i]--;
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					scanf("%d", &g[i][j][k] );
		}

		// #input

		solve();
	}

	return 0;
}