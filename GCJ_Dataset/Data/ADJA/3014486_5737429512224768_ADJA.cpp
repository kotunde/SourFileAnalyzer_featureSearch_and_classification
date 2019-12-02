#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 10500;

int tn;
int n, x;
int a[MAXN];

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &tn);

	for (int test = 1; test <= tn; test++) {
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		sort(a + 1, a + n + 1);

		int ans = 0;
		int l = 1, r = n;

		while (l <= r) {
			ans++;
			if (l < r && a[l] + a[r] <= x) 
				l++;
			r--;
		}	

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}