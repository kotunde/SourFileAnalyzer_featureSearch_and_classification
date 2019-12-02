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
using namespace std; 
typedef vector<int> vi; 
typedef vector<string> vs; 
typedef pair<int,int> pii; 
typedef long long ll; 
typedef unsigned long long ull; 
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

ull aC[111];
int aT[111];
ull bC[111];
int bT[111];

ull m2[111][111];

ull rec2(int ap, int bp);
ull recA(int ap, int bp, ull arem);
ull recB(int ap, int bp, ull brem);

ull recA(int ap, int bp, ull arem) 
{
	if (ap == N || bp == M)
		return 0;
	ull r = rec2(ap+1, bp);
	for (int i=bp; i<M; ++i) {
		if (bT[i] == aT[ap]) {
			if (bC[i] < arem) {
				r = max(r, bC[i] + recA(ap, i+1, arem - bC[i]));
			} else if (bC[i] > arem) {
				r = max(r, arem + recB(ap+1, i, bC[i] - arem));
			} else {
				r = max(r, arem + rec2(ap+1, i+1));
			}
			break;
		}
	}
	return r;
}

ull recB(int ap, int bp, ull brem) 
{
	if (ap == N || bp == M)
		return 0;
	ull r = rec2(ap, bp+1);
	for (int i=ap; i<N; ++i) {
		if (aT[i] == bT[bp]) {
			if (aC[i] < brem) {
				r = max(r, aC[i] + recB(i+1, bp, brem - aC[i]));
			} else if (aC[i] > brem) {
				r = max(r, brem + recA(i, bp+1, aC[i] - brem));
			} else {
				r = max(r, brem + rec2(i+1, bp+1));
			}
			break;
		}
	}
	return r;
}

ull rec2(int ap, int bp) 
{
	ull& r = m2[ap][bp];
	if (r != -1)
		return r;

	r = 0;

	if (ap == N || bp == M)
		return r = 0;

	if (aT[ap] == bT[bp]) {
		ull cnt = min(aC[ap], bC[bp]);
		ull newArem = aC[ap] - cnt;
		ull newBrem = bC[bp] - cnt;
		
		if (newArem > 0) {
			r = max(r, cnt + recA(ap, bp+1, newArem));
		} else if (newBrem > 0) {
			r = max(r, cnt + recB(ap+1, bp, newBrem));
		} else {
			r = max(r, cnt + rec2(ap+1,bp+1));
		}
	}

	r = max(r, rec2(ap+1, bp));
	r = max(r, rec2(ap, bp+1));
	r = max(r, rec2(ap+1, bp+1));

	return r;
}

int main()
{
	freopen("inC.txt", "r", stdin);
	freopen("outC.txt", "w", stdout);
	clock_t startTime = clock();

	int Cases;
	scanf("%d", &Cases);
	FOR(Case,0,Cases)
	{
		printf("Case #%d: ", Case+1);
		fprintf(stderr, "Case #%d: ", Case+1);

		fill(m2,-1);

		scanf("%d%d", &N, &M);
		FOR(i,0,N)
		{
			scanf("%llu%d", &aC[i], &aT[i]);
		}
		FOR(i,0,M)
		{
			scanf("%llu%d", &bC[i], &bT[i]);
		}
		ull res = rec2(0,0);
		printf("%llu\n", res);
		fprintf(stderr,"%llu\n", res);
	}

	clock_t endTime = clock();
	fprintf(stderr, "\nTime: %.3lf\n", double(endTime-startTime)/CLOCKS_PER_SEC);
	return 0;
} 
