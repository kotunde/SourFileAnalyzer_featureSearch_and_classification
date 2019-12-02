#pragma comment(linker,"/STACK:268435456")
#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <bitset>
#include <iterator>
#include <list>
#include <ctime>
#include <functional>

#define FR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,c,n) for(int (i)=(c);(i)<(n);(i)++)
#define REP(it,v,cont) for((cont)::iterator (it)=(v).begin();(it)!=(v).end();++(it))
#define CLR(a,c) memset((a),(c),sizeof (a))
#define ALL(v) (v).begin(),(v).end()
#define VCPRINT(v) for(int iii = 0;iii < (v).size();iii++) cout<<(v)[iii]<<" ";cout<<endl;
#define SETPRINT(v,cont) for((cont)::iterator iiit = (v).begin();iiit != (v).end();iiit++) cout<<*iiit<<" ";cout<<endl;

bool ascending (int i,int j) { return (i<j); }
bool descending (int i,int j) { return (i>j); }

typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PULI pair<unsigned long long,int>
#define PIL pair<int,long long>
#define PSI pair<string,int>
#define PSS pair<string,string>
#define PDD pair<double,double>
#define PIB pair<int,bool>
typedef long double ld;

using namespace std;

int n,m,k;
char C[20][20];

int count(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

bool visited[20][20];
bool dfs(int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=m) return true;
	if(visited[i][j]) return true;
	if(C[i][j]=='*') return true;
	if(i==0 || i==n-1 || j==0 || j==m-1) return false;
	visited[i][j]=true;
	bool ans = true;
	ans = ans && dfs(i-1,j);
	ans = ans && dfs(i,j-1);
	ans = ans && dfs(i+1,j);
	ans = ans && dfs(i,j+1);
	return ans;
}

int calculate()
{
	int ans = 0;
	FR(i,n) FR(j,m){CLR(visited,0); if(dfs(i,j)) ans++;}
	return ans;
}


int main()
{
	ifstream cin("a.in");
	ofstream cout("a.out");
	int T;cin>>T;
	FOR(_,1,T+1)
	{
		cout<<"Case #"<<_<<": ";
		cin>>n>>m>>k;
		int len = n*m;
		int MIN = len;
		FR(mask,1<<len)
		{
			FR(i,n) FR(j,m) if(1<<(i*m+j) & mask) C[i][j]='*';else C[i][j]='.';
			int ans = count(mask);
			if(calculate() >= k)
				MIN=min(MIN,ans);
		}
		cout<<MIN<<endl;
	}
}