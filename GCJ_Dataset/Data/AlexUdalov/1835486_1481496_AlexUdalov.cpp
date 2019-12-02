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

int n;
char s[5010];
set<int> a[34], aT[34];

inline int I(char c) { return (int)(c - 'a'); }
inline int cv(char x) {
	switch (x) {
		case 'o': return 26;
		case 'i': return 27;
		case 'e': return 28;
		case 'a': return 29;
		case 's': return 30;
		case 't': return 31;
		case 'b': return 32;
		case 'g': return 33;
		default: return 0;
	}
}

void edge(int s, int t) {
	a[s].insert(t);
	aT[t].insert(s);
}

void add(char c, char d) {
	edge(I(c), I(d));
	int x = cv(c), y = cv(d);
	if (x != 0) {
		if (y != 0) {
			edge(x, y);
			edge(x, I(d));
			edge(I(c), y);
		} else {
			edge(x, I(d));
		}
	} else if (y != 0) {
		edge(I(c), y);
	}
}

int go() {
	forn(i, 34) a[i].clear(), aT[i].clear();
	for (int i = 0; i < n-1; i++) add(s[i], s[i+1]);
	int ans = 0;
	forn(i, 34) ans += max(sz(a[i]) - sz(aT[i]), 0)/*, printf("a[%d] = %d, aT[%d] = %d\n", i, sz(a[i]), i, sz(aT[i]))*/;
	if (!ans) ans = 1;
	forn(i, 34) ans += sz(a[i]);
	return ans;
}


int main() {
	int __;
	scanf("%d", &__);
	forn(_, __) {
		printf("Case #%d:", _+1);
		int x;
		scanf("%d%s", &x, s);
		n = strlen(s);
		printf(" %d\n", go());
	}
	return 0;
}
