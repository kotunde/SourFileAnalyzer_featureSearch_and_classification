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

/*
char s[100], t[100];
char S[100], T[100];
bool b[65536];
*/
char a[100500];

int main() {
	/*
	int n = 0;
	forn(_, 3) {
		gets(s), gets(t);
		for (int i = 0; s[i]; i++) if (!b[s[i]]) {
			b[s[i]] = 1;
			S[n] = s[i];
			T[n] = t[i];
			n++;
		}
	}
	S[n] = T[n] = 0;
	puts(S), puts(T);
	*/
	const char* s = "ejpzmyslckdxvnribtahwfougq";
	const char* t = "ourqlangeismpbtdhwyxfckjvz";
	int __;
	scanf("%d\n", &__);
	forn(_, __) {
		gets(a);
		for (int i = 0; a[i]; i++) {
			forn(j, 26) if (s[j] == a[i]) { a[i] = t[j]; break; }
		}
		printf("Case #%d: ", _+1);
		puts(a);
	}
	return 0;
}
