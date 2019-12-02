#include <stdio.h>
#include <algorithm>
using namespace std;

int pt[101];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		int n, s, p;
		scanf("%d %d %d", &n, &s, &p);
		int cnt = 0, cnt2 = 0;
		for (int i=0; i<n; i++) {
			scanf("%d", &pt[i]);
			if (pt[i] < p + max(p-2,0) * 2)
				continue;
			int rem = pt[i] - p;
			if (rem < (p-1) * 2) {
				++cnt;
				++cnt2;
			}
			else
				++cnt;
		}
		printf("Case #%d: %d\n", scen, cnt - max(0, cnt2-s));
	}
	return 0;
}
