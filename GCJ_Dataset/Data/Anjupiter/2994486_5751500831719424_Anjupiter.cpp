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

int N;
string arr[100];
int solve()
{
	string ch;
	vector<vector<int>> cnt(100,vector<int>());
	ch.pb(arr[0][0]);
	cnt[0].pb(1);
	FOR(i,1,arr[0].length()-1)
	{
		if(arr[0][i]==ch[cnt[0].size()-1])cnt[0][cnt[0].size()-1]++;
		else{
			ch.pb(arr[0][i]);
			cnt[0].pb(1);
		}
	}
	//Check possible
	FOR(k,1,N-1)
	{
		string another=arr[k];
		rep(j,another.length())
		{
			if(j>0 && another[j-1]==another[j]){
				another.erase(another.begin()+j);
				--j;
			}
		}
		if(ch!=another)return -1;
		cnt[k].pb(1);
		FOR(i,1,arr[k].length()-1)
		{
			if(arr[k][i]==ch[cnt[k].size()-1])cnt[k][cnt[k].size()-1]++;
			else{
				cnt[k].pb(1);
			}
		}
	}
	int best=0;
	REP(j,cnt[0].size()){
		int sum=0;
		rep(i,N)sum+=cnt[i][j];
		int avg=sum/N;
		int rem=sum%N;
		if(rem>(N-rem))avg++;
		int gap=0;
		rep(i,N)gap+=abs(avg-cnt[i][j]);
		best+=gap;
	}
	return best;
}

int main()
{
	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		scanf("%d",&N);
		rep(i,N)cin>>arr[i];
		int ans=solve();
		if(ans>=0)printf("Case #%d: %d\n",t,ans);
		else printf("Case #%d: Fegla Won\n",t);
	}
	return 0;
}