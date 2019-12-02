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

int n,len;//N,L
vector<string> devices;
vector<string> flows;
vector<int> count_dev;
vector<int> count_flow;
int min_flopcount;

bool solve(int j,int flopcount)
{
	if(j>=len){
		bool ok=true;
		rep(i,n)if(devices[i]!=flows[i]){
			ok=false;break;
		}
		if(ok && min_flopcount>flopcount)
			min_flopcount=flopcount;
		return ok;
	}
	//1. 갯수가 다르면
	//2. 같으면 해당 위치 비교해보고 다르면
	//3. 분기
	if(count_dev[j]!=count_flow[j]){//flop flow
		rep(i,n)flows[i][j]=(flows[i][j]=='1')?'0':'1';
		//Validation check
		SORT(devices);
		SORT(flows);
		rep(i,n)if(devices[i][j]!=flows[i][j]){
			rep(i,n)flows[i][j]=(flows[i][j]=='1')?'0':'1';//원복
			return false;
		}
		bool ok=solve(j+1,flopcount+1);
		rep(i,n)flows[i][j]=(flows[i][j]=='1')?'0':'1';//원복
		return ok;
	}else{
		//그냥 해보고 Flop한 다음 해보고.
		SORT(devices);
		SORT(flows);
		bool need_flop=false;
		rep(i,n)if(devices[i][j]!=flows[i][j]){
			need_flop=true;break;
		}
		bool ok=false;
		if(!need_flop)ok = solve(j+1,flopcount);
		
		rep(i,n)flows[i][j]=(flows[i][j]=='1')?'0':'1';
		//Validation check
		SORT(devices);
		SORT(flows);
		rep(i,n)if(devices[i][j]!=flows[i][j]){
			rep(i,n)flows[i][j]=(flows[i][j]=='1')?'0':'1';//원복
			return ok;
		}
		ok=ok || solve(j+1,flopcount+1);
		rep(i,n)flows[i][j]=(flows[i][j]=='1')?'0':'1';//원복

		return ok;
	}
	return true;
}

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		scanf("%d %d",&n,&len);
		devices.resize(n,"");
		flows.resize(n,"");
		rep(i,n)cin>>devices[i];
		rep(i,n)cin>>flows[i];
		
		count_dev=vector<int>(len,0);
		count_flow=vector<int>(len,0);
		rep(i,n)rep(j,len){
			if(devices[i][j]=='1')count_dev[j]++;
			if(flows[i][j]=='1')count_flow[j]++;
		}
		bool ispossible=true;
		rep(j,len){
			if(count_dev[j]!=count_flow[j] &&
				count_dev[j]!=n-count_flow[j]){
				ispossible=false;break;
			}
		}
		if(!ispossible){
			printf("Case #%d: NOT POSSIBLE\n",t);
			continue;
		}
		min_flopcount = INT_MAX;
		ispossible=solve(0,0);
		if(ispossible)printf("Case #%d: %d\n",t,min_flopcount);
		else printf("Case #%d: NOT POSSIBLE\n",t);
	}
	return 0;
}