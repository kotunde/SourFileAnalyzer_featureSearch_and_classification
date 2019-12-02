#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:16777216")
#include <random>
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

int N, W, L;

int r[1111];
#define MAX_ITER 1000
#define MAX_ITER_GLOBAL 10000

inline double sqr(double x) { return x*x; }

inline double dist2(double x1, double y1, double x2, double y2) 
{
	return sqr(x1-x2) + sqr(y1-y2);
}

vector<pair<int, pair<double, double>> > solve(vector<pii>& r)
{
	std::uniform_real_distribution<double> unif(0, 1.0);
   std::default_random_engine re;
	vector<pair<int, pair<double, double>>> res;
	FOR(i,0,N) {
		bool found = false;
		FOR(j,0,MAX_ITER) {

			double x = unif(re) * W;
			double y = unif(re) * L;
			pair<double,double> cur = mp(x,y);

			bool ok = true;
			FOR(k,0,sz(res)) {
				double dst2 = dist2(res[k].second.first, res[k].second.second, cur.first, cur.second);
				if (dst2 < sqr(r[i].second + r[k].second + 1e-9))
				{
					ok = false;
					break;
				}
			}

			if (ok)
			{
				res.pb(mp(r[i].first, cur));
				found = true;
				break;
			}
		}
		if (!found)
			return res;
	}
	return res;
}

int main()
{
	freopen("inB.txt", "r", stdin);
	freopen("outB.txt", "w", stdout);
	clock_t startTime = clock();

	int Cases;
	scanf("%d", &Cases);
	FOR(Case,0,Cases)
	{
		print("Case #%d: ", Case+1);
		scanf("%d%d%d", &N, &W, &L);
		FOR(i,0,N)
		{
			scanf("%d", &r[i]);
		}
		bool found = false;

		vector<pii> t;
		FOR(i,0,N)
			t.pb(mp(i,r[i]));

		FOR(i,0,MAX_ITER_GLOBAL) {
			 std::random_shuffle(all(t));
			vector<pair<int, pair<double,double>> > res = solve(t);
			if (sz(res) == N) {
				sort(all(res));
				found = true;
				FOR(j,0,N) {
					print("%6lf %6lf%c", res[j].second.first, res[j].second.second, j == N-1 ? '\n' : ' ');
				}
				break;
			}
		}
		if (!found) {
			print("BLAH!\n");
		}
	}

	clock_t endTime = clock();
	fprintf(stderr, "\nTime: %.3lf\n", double(endTime-startTime)/CLOCKS_PER_SEC);
	return 0;
} 
