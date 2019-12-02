#pragma comment(linker, "/STACK:10000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> T inline sqr(T x) { return x * x; }
template <class T> string str( T i ) { stringstream ss; ss << i; return ss.str(); }
int toint(string a) {istringstream is(a); int p; is>>p; return p;}
long long toll(string a){istringstream is(a);long long p;is>>p;return p;}

#define pb push_back
#define mp make_pair
#define e1 first
#define e2 second
#define sz size

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif
#define forn(i, n) for (i = 0; i < int(n); i++)
#define setval(a,v) memset(a, v, sizeof(a))
const ld pi = 3.1415926535897932384626433832795, eps = 1e-8;

int a[10];
pii b[10];
int s, p;
int ans;

inline void gen(int x)
{
	if (x == 3)
	{
		int i, q = 0;
		forn (i, x)
			if (b[i].e2 - b[i].e1 == 2)
			{
				q++;
			}
		if (q != s)
			return;
		q = 0;
		forn (i, x)
			if (b[i].e2 >= p)
				q++;
		ans = max(ans, q);
		return;
	}
	int i, j, z;
	forn (i, a[x] + 1)
		for (j = i; j <= i + 2; j++)
		{
			z = a[x] - i - j;
			if (z >= 0)
			{
				b[x].e1 = min(z, i);
				b[x].e2 = max(z, j);
				if (b[x].e2 - b[x].e1 <= 2)
					gen(x + 1);
			}
		}
}

int main()
{
   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   int it, t, n, i;
	cin >> t;
	forn (it, t)
	{
		cin >> n >> s >> p;
		ans = 0;
		forn (i, 3)
			a[i] = 0;
		forn (i, n)
			cin >> a[i];
		gen(0);
		ans = min(ans, n);
		cout << "Case #" << it + 1 << ": " << ans << endl;
	}
	return 0;
}
