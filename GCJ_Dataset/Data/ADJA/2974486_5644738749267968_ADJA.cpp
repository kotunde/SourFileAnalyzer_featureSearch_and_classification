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

const int MAXN = 1050;

int t;
int n;
double a[MAXN], b[MAXN];
vector < pair<double, int> > v;
int war, dw;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lf", &a[i]);
		}

		for (int i = 1; i <= n; i++) {
			scanf("%lf", &b[i]);
		}

		v.clear();

		for (int i = 1; i <= n; i++) {
			v.push_back(make_pair(a[i], 1));
			v.push_back(make_pair(b[i], 2));
		}
		sort(v.begin(), v.end());

		war = 0; dw = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (v[i].second == 1)
				war++;
			else {
				if (war)
					war--;
			}	
		}

		for (int i = 0; i < 2 * n; i++) {
			if (v[i].second == 2) 
				dw++;
			else {
				if (dw)
					dw--;
			}
		}

		dw = n - dw;

	    printf("Case #%d: %d %d\n", test, dw, war);
	}

	return 0;
}