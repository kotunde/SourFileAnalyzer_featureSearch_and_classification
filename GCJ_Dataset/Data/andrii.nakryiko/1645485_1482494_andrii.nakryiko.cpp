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

bool done1[1111];
bool done2[1111];

int main()
{
	freopen("inB.txt", "r", stdin);
	freopen("outB.txt", "w", stdout);
	clock_t startTime = clock();

	int Cases;
	scanf("%d", &Cases);
	FOR(Case,0,Cases)
	{
		printf("Case #%d: ", Case+1);
		fprintf(stderr, "Case #%d: ", Case+1);
		vector<pair<pii, int>> levels1;
		vector<pair<pii, int>> levels2;
		fill(done1,0);
		fill(done2,0);
		scanf("%d", &N);
		FOR(i,0,N){
			int a,b;
			scanf("%d%d", &a, &b);
			levels1.pb(mp(mp(a, -b),i));
			levels2.pb(mp(mp(b, -a),i));
		}

		sort(all(levels1));
		sort(all(levels2));
		int sc = 0;
		int r = 0;

		int d1=0;
		int d2=0;
		bool bad=false;
		while(d2<N)
		{
			if (levels2[d2].first.first <= sc) 
			{
				int p = levels2[d2].second;
				done2[p] = true;
				++r;
				++d2;
				sc += done1[p] ? 1 : 2;
			} 
			else if (d1<N) {
				int p = levels1[d1].second;
				if (done2[p])
				{
					++d1;
					continue;
				}

				if (levels1[d1].first.first <= sc) 
				{
					done1[p] = true;
					sc += 1;
					r++;
					++d1;
				} 
				else 
				{
					bad = true;
					break;
				}
			} 
			else
			{
				bad = true;
				break;
			}
		}

		if (bad) 
		{
			printf("Too Bad\n");
			fprintf(stderr, "Too Bad\n");
		}
		else {
			printf("%d\n", r);
			fprintf(stderr, "%d\n", r);

			continue;
			//if (N >= 5)
			//	continue;

			vi perm;
			FOR(i,0,N)
				perm.pb(i);

			do {
				vector<pair<pii, int>> lvls1 = levels1;
				vector<pair<pii, int>> lvls2;
				FOR(i,0,N)
					lvls2.pb(levels2[perm[i]]);

				bool bd = false;
				FOR(i,1,N)
					if (lvls2[i].first.first < lvls2[i-1].first.first)
					{
						bd = true;
						break;
					}

				if (bd)
					continue;

				int sc1 = 0;
				int r1 = 0;
				fill(done1,0);
				fill(done2,0);
				int d1=0;
				int d2=0;
				while(d2<N)
				{
					if (lvls2[d2].first.first <= sc1) 
					{
						int p = lvls2[d2].second;
						done2[p] = true;
						++r1;
						++d2;
						sc1 += done1[p] ? 1 : 2;
					} 
					else if (d1<N) {
						int p = lvls1[d1].second;
						if (done2[p])
						{
							++d1;
							continue;
						}

						if (lvls1[d1].first.first <= sc1) 
						{
							done1[p] = true;
							sc1 += 1;
							r1++;
							++d1;
						} 
						else 
						{
							bad = true;
							break;
						}
					} 
					else
					{
						bad = true;
						break;
					}
				}

				if (r1 < r) {
					fprintf(stderr, "NO!!!!!!!!!!!!!!!\n");
					break;
				}
			} while (next_permutation(all(perm)));
		}
	}

	clock_t endTime = clock();
	fprintf(stderr, "\nTime: %.3lf\n", double(endTime-startTime)/CLOCKS_PER_SEC);
	return 0;
} 
