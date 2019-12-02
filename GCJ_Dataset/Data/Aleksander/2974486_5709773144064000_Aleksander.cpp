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

const double inf = 1e50;

double cookieFarmCost, cookieFarmAdd, needCookies;

bool doubleEqual (double val1, double val2)
{
	return fabs(val1 - val2) < 1e-9;
}
bool doubleLess (double val1, double val2)
{
	return val1 < val2 && !doubleEqual(val1, val2);
}

void solve ()
{
	double ans = inf;
	double cookiesAdd = 2;
	double t = 0;

	for (int i = 0; i < needCookies; i++)
	{
		double curAns = t + needCookies / cookiesAdd;
		if (doubleLess(curAns, ans) )
			ans = curAns;

		t += cookieFarmCost / cookiesAdd;
		cookiesAdd += cookieFarmAdd;
	}

	printf("%.12lf", ans);
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

		scanf("%lf%lf%lf", &cookieFarmCost, &cookieFarmAdd, &needCookies);

		// #input

		solve();
	}

	return 0;
}