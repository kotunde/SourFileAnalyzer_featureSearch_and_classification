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

inline bool f(int x, int y)
{
	string sx = str(x), sy = str(y);
	if (sx.sz() != sy.sz())
		return false;
	int n = sx.sz(), i;
	forn(i, n)
	{
		if (sy == sx.substr(i, n - i) + sx.substr(0, i))
			return true;
	}
	return false;
}
int main()
{
   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   int t, i, ii, j, ans, a, b;
	cin >> t;
	forn (ii, t)
	{
		cout << "Case #" << ii + 1 << ": ";
		cin >> a >> b;
		ans = 0;
		for (i = a; i < b; i++)
			for (j = i + 1; j <= b; j++)
				if (f(i, j))
					ans++;
		cout << ans;
		cout << endl;
	}
	return 0;
}
