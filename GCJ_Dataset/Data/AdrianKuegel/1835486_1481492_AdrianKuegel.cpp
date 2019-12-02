#include <stdio.h>
#include <climits>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int p[300], s[300];
int bestPrice[2000001];
int dp[2000001];

int main() {
	int tc, m, f, n;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		scanf("%d %d %d", &m, &f, &n);
		priority_queue< pair<int, int> > Q;
		for (int i=0; i<n; ++i) {
			scanf("%d %d", &p[i], &s[i]);
			Q.push(make_pair(-p[i], s[i]));
		}
		bestPrice[0] = f;
		for (int i=1; i<=2000000; ++i)
		{
			while(!Q.empty() && Q.top().second < i-1)
				Q.pop();
			if (Q.empty())
				bestPrice[i] = INT_MAX;
			else {
				bestPrice[i] = bestPrice[i-1] - Q.top().first;
			}
		}
		// try how many days it lasts by binary search
		int lo = 0, hi = m +  1;
		while(lo < hi) {
			int mid = (lo + hi + 1) / 2;
			int best = INT_MAX;
			// try to divide it into chunks
			for (int parts=1; parts<=mid; ++parts)
			{
				int size_per_part = mid / parts;
				int how_many = mid % parts;
				long long val;
				if (how_many == 0)
				{
					val = bestPrice[size_per_part] * ((long long)parts);
				}
				else {
					val = ((long long)how_many)*bestPrice[size_per_part+1] + (parts - (long long)how_many) * bestPrice[size_per_part];
				}
				if (val < best)
					best = val;
			}
			if (best <= m) {
				lo = mid;
			}
			else
				hi = mid-1;
		}
		printf("Case #%d: %d\n", scen, lo);
	}
	return 0;
}
