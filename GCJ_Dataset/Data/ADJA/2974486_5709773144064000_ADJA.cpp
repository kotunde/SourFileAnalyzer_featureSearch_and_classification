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

const double INF = 1e10;

int t;
double cost, up, need;
double speed;
double timer;
double ct, ft;
double ans;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		scanf("%lf %lf %lf", &cost, &up, &need);
		speed = 2.0;
		timer = 0.0;

		ans = INF;

		while (true) {	
			ct = need / speed;
			ft = cost / speed;

			ans = min(ans, timer + ct);

			timer += ft;
			speed += up;

			if (timer >= ans)
				break;
		}

		printf("Case #%d: %.12lf\n", test, ans);
	}

	return 0;
}