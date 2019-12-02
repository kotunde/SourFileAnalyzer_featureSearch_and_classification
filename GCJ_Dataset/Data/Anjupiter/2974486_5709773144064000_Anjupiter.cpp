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

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		double c,f,x;
		scanf("%lf %lf %lf",&c,&f,&x);
		double best = x/2;
		double elapsed = 0;
		double produce = 2;
		//사는 경우를 tests
		int farm_count = 0;
		while(true){
			double t_buyfarm = elapsed + c/produce;
			double t_reachx = t_buyfarm + x/(produce+f);
			if(t_reachx<best){
				farm_count++;
				best=t_reachx;
				elapsed = t_buyfarm;
				produce+=f;
			}else break;
		}
		printf("Case #%d: %.7lf\n",t,best);
	}
	return 0;
}