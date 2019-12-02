
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

const int MAXN = 1000;
pair<ll,ll> meals[MAXN];
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		ll M,F;
		int N;
		cin >> M >> F >> N;
//		cout << M << " "<< F <<  " "<< N << endl;
		FOR(i,0,N)cin >> meals[i].first >> meals[i].second;
		sort(meals,meals+N);
		int ne = 1;
		FOR(i,1,N){
			if(meals[i].second > meals[ne-1].second)meals[ne++] = meals[i];
		}
		FOR(i,0,N)meals[i].second++;
		ll res = 0;
		N = ne;
		ll last = 0;
		ll co = F;
//		if(tcc == 7)cout << M << endl;
		FOR(i,0,N){
			if(co > M)break;
			ll mnext = min(meals[i].second - last, (M - co) / meals[i].first);
			ll nco = co + mnext * meals[i].first;
//			if(tcc == 7)cout << "i= " << i << ": " << co << " " << nco << endl;
			if(mnext == 0)break;
			ll maxTurns = M / co;
			ll minTurns = (M + nco - 1) / nco;
			ll cres = 0;
//	if(tcc == 7)			cout << maxTurns << " "<< minTurns << endl;
			if(maxTurns < minTurns){
				co = nco;
				last += mnext;
				continue;
			}
			int ST = 1000;
			while(ST-->0 && maxTurns >= minTurns){
//				cout <<"("<< minTurns << " " << maxTurns << ")" << endl;
				cres = max(cres,max(maxTurns * last + (M - maxTurns * co) / meals[i].first,minTurns * last + (M - minTurns * co) / meals[i].first));
//				cout << "cres = " << cres << endl;
				--maxTurns;
				++minTurns;
			}
			res = max(cres,res);
			co = nco;
			last += mnext;
		}
//		cout << "FINAL " << last << " " << co << endl;
		res = max(res, last * (M / co));
		cout << "Case #" << tcc << ": " << res << endl;
	}
	return 0;
}
