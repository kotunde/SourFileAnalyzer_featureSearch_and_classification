#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define eprintf(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define sz(v) ((int)((v).size()))
typedef pair<int, int> ii;
typedef long long LL;

int main() {
	int __;
	scanf("%d", &__);
	forn(_, __) {
		int A, B;
		scanf("%d%d", &A, &B);
		int ans = 0;
		for (int i = A; i <= B; i++) {
			int x = i;
			int t = 1;
			while (x) t *= 10, x /= 10;
			t /= 10;
			x = i;
			while (1) {
				bool b = !!(x%10);
				x = (x / 10) + t*(x%10);
				if (x == i) break;
				if (b && i < x && x <= B) ans++;
			}
		}
		printf("Case #%d: %d\n", _+1, ans);
	}
	return 0;
}
