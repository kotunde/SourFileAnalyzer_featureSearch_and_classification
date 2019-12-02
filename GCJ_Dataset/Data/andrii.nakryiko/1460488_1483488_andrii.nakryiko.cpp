#define _CRT_SECURE_NO_DEPRECATE
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
int N, M, K;
int A, B;
char buf[50], buf2[50];

set<pii> all;
int len;

void calcFor(int x) {
	sprintf(buf, "%d", x);
	int y;
	FOR(i,1,len) {
		if (buf[i] == '0')
			continue;
		FOR(j,0,len)
			buf2[j] = buf[(j+i)%len];
		buf2[len] = 0;
		sscanf(buf2, "%d", &y);
		if (y < A || y > B || x == y)
			continue;
		all.insert(mp(min(x,y), max(x,y)));
	}
}

int main()
{
	freopen("inC.txt", "r", stdin);
	freopen("outC.txt", "w", stdout);
#define SHOW_TIME
#ifdef SHOW_TIME
	clock_t startTime = clock();
#endif

	int Q;
	scanf("%d", &Q);
	FOR(q,0,Q)
	{
		printf("Case #%d: ", q+1);
		fflush(stdout);

		all.clear();
		scanf("%d%d", &A, &B);
		
		sprintf(buf, "%d", A);
		len = strlen(buf);

		FOR(i,A,B+1) {
			calcFor(i);
		}
		printf("%d\n", sz(all));
	}

#ifdef SHOW_TIME
	clock_t endTime = clock();
	fprintf(stderr, "\nTime: %.3lf\n", double(endTime-startTime)/CLOCKS_PER_SEC);
#endif
	return 0;
} 
