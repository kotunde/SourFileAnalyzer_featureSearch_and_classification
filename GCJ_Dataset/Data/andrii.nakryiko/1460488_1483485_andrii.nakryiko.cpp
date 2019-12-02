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
char s[200], t[200];

char from[3][200] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

char to[3][200] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

char m[256];

int main()
{
	freopen("inA.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#define SHOW_TIME
#ifdef SHOW_TIME
	clock_t startTime = clock();
#endif

	FOR(i,0,3) {
		int j=0;
		while(from[i][j]) {
			m[from[i][j]] = to[i][j];
			++j;
		}
	}

	m['y'] = 'a';
	m['e'] = 'o';
	m['q'] = 'z';

	char m1=' ', m2=0;
	FOR(i,'a','z'+1) {
		m2 ^= i;
	}
	FOR(i,'a','z'+1) {
		if (m[i] == 0) {
			m1 = i;
		} else {
			m2 ^= m[i];
		}
	}
	m[m1] = m2;

	int Q;
	scanf("%d\n", &Q);
	FOR(q,0,Q)
	{
		printf("Case #%d: ", q+1);
		fflush(stdout);

		gets(s);
		int i=0;
		while (s[i]) 
		{
			t[i] = m[s[i]];
			++i;
		}
		t[i] = 0;
		puts(t);
	}

#ifdef SHOW_TIME
	clock_t endTime = clock();
	fprintf(stderr, "\nTime: %.3lf\n", double(endTime-startTime)/CLOCKS_PER_SEC);
#endif
	return 0;
} 
