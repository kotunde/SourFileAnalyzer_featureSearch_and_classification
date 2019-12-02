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

#ifdef _MSC_VER
#include <intrin.h>
int ctz(unsigned v){
	unsigned long index;
	_BitScanForward(&index,v);
	return index;
}
#else
#define __popcnt __builtin_popcount 
#define ctz(x) __builtin_ctz(x)
#endif

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		int temp[4];
		int r[2],sel[2]={};
		rep(k,2){
			scanf("%d",&r[k]);
			rep(i,4){
				scanf("%d %d %d %d",&temp[0],&temp[1],&temp[2],&temp[3]);
				if(i+1==r[k])rep(j,4)
					sel[k] |= 1<<temp[j];
			}
		}
		int ans = __popcnt(sel[0] & sel[1]);
		if(ans==1){
			ans=ctz(sel[0] & sel[1]);
			printf("Case #%d: %d\n",t,ans);
		}else if(ans>1)
			printf("Case #%d: Bad magician!\n",t);
		else
			printf("Case #%d: Volunteer cheated!\n",t);
	}
	return 0;
}