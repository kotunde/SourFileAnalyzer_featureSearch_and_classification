#pragma comment(linker, "/STACK:66777216")
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <assert.h>
#include <memory.h>
#pragma hdrstop

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define y0 __MY_Y0__
#define y1 __MY_Y1__
#define sz(a) (int)a.size()
#define fill(a, x) memset (a, x, sizeof(a))

#ifdef _DEBUG
	#define Eo(x) {cout << "# " << #x << " = " << (x) << endl;}
	#define E(x) {cout << "# " << #x << " = " << (x) << " ";}
	#define Ou(x) {cout << "# " << (x) << endl;}
	#define OK {cout << "# OK    Line : " << __LINE__ << endl;}
#else
	#define Eo(x)
	#define E(x)
	#define Ou(x)
	#define OK
#endif

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

inline void sIO() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
}
inline void iIO() {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
inline void fIO(string fn) {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
#else
	freopen((fn + ".in").c_str(), "r", stdin); freopen((fn + ".out").c_str(), "w", stdout);
#endif
}
inline void TM() {
#ifdef _DEBUG
	cout << endl << "# Time: " << clock() / 1000. << endl;
#endif
}
template<class T> inline T abs(T x) {return x < 0 ? -x : x;}
template<class T> inline T sqr(T x) {return x * x;}
template<class T> inline T gcd(T a, T b) {if (a < b) swap(a, b); while (b) {a %= b; swap(a, b);} return a;}
template<class T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template<class T> inline bool isPrime(T n) {if (n < 2) return false; T kk = (T)sqrt(n + 0.); for (T i = 2; i <= kk; ++i) if (!(n % i)) return false; return true;}
template<class T> inline string toa(T x) {stringstream ss; ss << x; string ret; ss >> ret; return ret;}
template<class T> inline T ppow(T a, ll b) {T ret = 1; while (b) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
inline int toi(string s) {stringstream ss; ss << s; int ret; ss >> ret; return ret;}
inline ll tol(string s) {stringstream ss; ss << s; ll ret; ss >> ret; return ret;}
inline void swap(short& a, short& b) {b ^= a ^= b ^= a;}
inline void swap(int& a, int& b) {b ^= a ^= b ^= a;}
inline void swap(char& a, char& b) {b ^= a ^= b ^= a;}
inline void swap(ll& a, ll& b) {b ^= a ^= b ^= a;}
inline char upperCase(char ch) {return (ch >= 'a' && ch <= 'z') ? ch^32 : ch;}
inline char lowerCase(char ch) {return (ch >= 'A' && ch <= 'Z') ? ch^32 : ch;}
inline string upperCase(string s) {int ls = s.length(); for (int i = 0; i < ls; ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] ^= 32; return s;}
inline string lowerCase(string s) {int ls = s.length(); for (int i = 0; i < ls; ++i) if (s[i] >= 'A' && s[i] <= 'Z') s[i] ^= 32; return s;}
inline int dig(char ch) {return ch - 48;}
inline bool isAlpha(char ch) {return (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z');}
inline bool isDigit(char ch) {return (ch >= '0' && ch <= '9');}
inline bool isLowerCase(char ch) {return (ch >= 'a' && ch <= 'z');}
inline bool isUpperCase(char ch) {return (ch >= 'A' && ch <= 'Z');}

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const int MD = 1000000007;

int __;

int n, a[2222], rr[2222], curMax, mx, ff[2222], st[2222][2], tp;
bool bad, w[2222];

int main() {
	sIO();
	scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		scanf("%d", &n);
		fill(w, 0);
		fill(ff, 0);
		for (int i = 1; i < n; ++i)
			scanf("%d", a + i);
		ff[1] = 1;
		bad = false;
		rr[1] = n;
		mx = 1;
		st[1][0] = a[1];
		st[1][1] = 1;
		tp = 1;
		for (int i = 2; i <= n; ++i)
			if (i == st[tp][0]) {
				rr[i] = rr[st[tp][1]] + i - st[tp][1];
				--tp;
				if (tp && a[i] > st[tp][0]) {
					bad = true;
					break;
				}
				if (!tp || a[i] < st[tp][0]) {
					st[++tp][0] = a[i];
					st[tp][1] = i;
				} else st[tp][1] = i;
			} else {
				rr[i] = rr[i - 1];
				if (tp && a[i] > st[tp][0]) {
					bad = true;
					break;
				}
				if (a[i] < st[tp][0]) {
					st[++tp][0] = a[i];
					st[tp][1] = i;
				}
			}
		if (bad) printf("Impossible"); else 
			for (int i = 1; i <= n; ++i)
				printf("%d ", rr[i]);
		printf("\n");
	}
	return 0;
}