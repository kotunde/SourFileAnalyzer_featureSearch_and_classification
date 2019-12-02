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

int n;
double naomi[1000],ken[1000];
bool vis_naomi[1000];
bool vis_ken[1000];

//Debug
//int best_naomi[1000],best_ken[1000];

int solve_optimal(int step)
{
	if(step<n){
		//Find unvisit
		int best_value=-1;
		rep(i,n)if(!vis_naomi[i]){
			//ken
			int best_idx=-1;
			rep(j,n)if(!vis_ken[j] && ken[j]>naomi[i]){
				best_idx=j;
				break;
			}
			if(best_idx==-1){
				//Find minist
				rep(j,n)if(!vis_ken[j]){
					best_idx=j;
					break;
				}
			}
			vis_naomi[i]=true;
			vis_ken[best_idx]=true;
			int value = (naomi[i]>ken[best_idx]?1:0)+solve_optimal(step+1);
			vis_naomi[i]=false;
			vis_ken[best_idx]=false;
			if(best_value<value){
				best_value=value;
				//best_naomi[step]=i;
				//best_ken[step]=best_idx;
			}
		}
		return best_value;
	}
	return 0;
}

int solve_deceit()
{
	int a=0,b=0;//a,naomi,b,ken
	int value=0;
	for(;a<n;a++){
		if(naomi[a]>ken[b]){
			b++;
			value++;
		}	
	}
	return value;
}

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		scanf("%d",&n);
		rep(i,n)scanf("%lf",&naomi[i]);
		rep(i,n)scanf("%lf",&ken[i]);
		sort(naomi,naomi+n);
		sort(ken,ken+n);

		CLEAR(vis_naomi);
		CLEAR(vis_ken);
		int deceit = solve_deceit();
		int opt = solve_optimal(0);

		printf("Case #%d: %d %d\n",t,deceit,opt);
	}
	return 0;
}