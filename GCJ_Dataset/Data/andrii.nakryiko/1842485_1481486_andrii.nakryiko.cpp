#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:16777216")
#include <ctime>
#include <string> 
#include <vector> 
#include <map> 
#include <list> 
#include <set> 
#include <queue> 
#include <iostream> 
#include <sstream> 
#include <stack> 
#include <deque> 
#include <cmath> 
#include <memory.h> 
#include <cstdlib> 
#include <cstdio> 
#include <cctype> 
#include <algorithm> 
#include <utility> 
#include <cstdarg>
using namespace std; 
typedef vector<int> vi; 
typedef vector<string> vs; 
typedef pair<int,int> pii; 
typedef long long ll; 
typedef istringstream iss;
#define FOR(i,f,n) for(int i=f; i<n; ++i) 
#define sz(a) ((int)a.size()) 
#define fill(w,v) memset(w,v,sizeof(w)) 
#define pb push_back 
#define all(a) a.begin(),a.end()
#define mp make_pair 
#define inf 1000000000 
#define X first
#define Y second
template<class T> inline T gcd(T a, T b){T t; while (a && b) t = a, a = b%a, b = t; return a+b; }
template<class T> inline T power(T a, int p) {T r = T(1); while (p) { if (p&1) r = r*a; a = a*a; p >>= 1; } return r; }
template<class T> T extgcd(T a, T b, T& x, T& y) { if (b==0) return x=1, y=0, a; T x1, y1, g; g = extgcd(b, a%b, x1, y1); x = y1; y = x1 - a/b*y1; return g; }
template<class T> inline T Floor(T a, T b) { if (b<0) a=-a, b=-b; if (a<0) return (a-b+1)/b; return a/b; }
template<class T> inline T Ceil(T a, T b) { if (b<0) a=-a, b=-b; if (a<0) return a/b; return (a+b-1)/b; }
void print(const char *fmt, ...)  { va_list args; va_start(args, fmt); vprintf(fmt, args); vfprintf(stderr, fmt, args); va_end(args); }

int N, M, K, L;

#define MAXN 10011

int d[MAXN];
int len[MAXN];

bool was[MAXN][MAXN];
bool can[MAXN][MAXN];

bool rec(int prev, int cur) 
{
	if (was[prev][cur])
		return can[prev][cur];

	was[prev][cur] = true;
	if (cur == N-1)
	{
		can[prev][cur] = true;
		return true;
	}

	int curH = min(len[cur], d[cur] - d[prev]);
	FOR(i,cur+1, N)
	{
		if (d[i] - d[cur] > curH)
			break;
		if (rec(cur, i))
		{
			can[prev][cur] = true;
			return true;
		}
	}
	return can[prev][cur] = false;
}

int main()
{
	freopen("inA.txt", "r", stdin);
	freopen("outA.txt", "w", stdout);
	clock_t startTime = clock();

	int Cases;
	scanf("%d", &Cases);
	FOR(Case,0,Cases)
	{
		print("Case #%d: ", Case+1);
		scanf("%d", &N);
		FOR(i,0,N) {
			scanf("%d%d", &d[i+1], &len[i+1]);
		}
		scanf("%d", &L);
		d[0] = 0;
		len[0] = d[1];
		d[N+1] = L;
		len[N+1] = inf;
		N+=2;

		fill(was,0);
		fill(can,0);

		bool found = rec(0,1);
		print("%s\n", found ? "YES" : "NO");
	}

	clock_t endTime = clock();
	fprintf(stderr, "\nTime: %.3lf\n", double(endTime-startTime)/CLOCKS_PER_SEC);
	return 0;
} 
