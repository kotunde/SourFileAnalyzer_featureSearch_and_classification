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
		int n, x;
		scanf("%d", &n);
		vector<ii> a;
		forn(i, n) scanf("%d", &x);
		forn(i, n) {
			scanf("%d", &x);
			a.push_back(ii(-x, i));
		}
		sort(a.begin(), a.end());
		printf("Case #%d:", _+1);
		forit(it, a) printf(" %d", it->second);
		puts("");
	}
	return 0;
}
