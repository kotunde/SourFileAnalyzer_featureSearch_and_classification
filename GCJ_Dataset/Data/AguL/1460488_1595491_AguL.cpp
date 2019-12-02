#include <cstdio>
#include <algorithm>

using namespace std;

int __, ans, s, p, n, cd, gd, k, tt, qq;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &__);
	for (int _ = 1; _ <= __; _++) {
		scanf("%d %d %d", &n, &s, &p);
		ans = 0;
		cd = 0;
		gd = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &k);
			tt = k % 3;
			if (tt == 1) {
				qq = k / 3 + 1;
				ans += (qq >= p);
			} else
			if (tt == 2) {
				qq = k / 3 + 1;
				if (qq >= p) {
					ans++;
					gd++;
				} else
				if (qq + 1 >= p) cd++;
			} else {
				qq = k / 3;
				if (qq >= p) {
					ans++;
					gd++;
				} else
				if (qq + 1 >= p && qq > 0) cd++;
			}
		}
		ans += min(cd, s);
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}