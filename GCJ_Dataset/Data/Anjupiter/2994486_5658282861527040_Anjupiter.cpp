//TAG : 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include <climits>
using namespace std;

#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,n) for (int (i)=0,_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b) for (int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset((x),0,sizeof(x));
#define CLEARA(x) memset(&(x),0,sizeof(x));
#define FILL(x,v) memset((x),(v),sizeof(x));
#define FILLA(x,v) memset(&(x),(v),sizeof(x));

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
//const double pi = acos(-1.0);
#define EPS 1e-9

#define LL long long

#ifdef _MSC_VER
#include <intrin.h>
int ctz(unsigned v){
	unsigned long index;
	_BitScanForward(&index,v);
	return index;
}
#define strtoll	_strtoi64
int __popcnt64(unsigned long long v)
{
	return __popcnt((unsigned)(v>>32))+__popcnt((unsigned)(v&UINT_MAX));
}
#else
#define ctz(x) __builtin_ctz(x)
#define __popcnt	__builtin_popcount 
#define __popcnt64	__builtin_popcountll
#endif

LL A,B,K;

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		scanf("%lld %lld %lld",&A,&B,&K);
		LL ans=0;
		/*if(A<=K || B<=K)ans=A*B;
		else{
			ans=A*B-(K-A)*(K-B);
			for(LL i=K+1;i<A;i++)
				for(LL j=K+1;j<B;j++)
					if((i&j)<K)ans++;
		}*/
		for(LL i=0;i<A;i++)
			for(LL j=0;j<B;j++)
				if((i&j)<K)ans++;
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}