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

int n,m;
char G[510][110];
PII P[510][110];
bool vis[510][110];


bool bfs()
{
	CLR(vis,0);
	queue<PII> Q;
	FR(i,m){ P[0][i]=PII(-1,-1); if(G[0][i]!='#'){ Q.push(PII(0,i)); vis[0][i]=true;}}
	while(Q.size())
	{
		PII v = Q.front();Q.pop();
		if(v.first < n-1 && !vis[v.first+1][v.second] && G[v.first+1][v.second]!='#')
		{
			vis[v.first+1][v.second]=true;
			P[v.first+1][v.second] = v;
			Q.push(PII(v.first+1,v.second));
			if(v.first+1==n-1) return true;
		}

		if(v.first > 0 && !vis[v.first-1][v.second] && G[v.first-1][v.second]!='#')
		{
			vis[v.first-1][v.second]=true;
			P[v.first-1][v.second] = v;
			Q.push(PII(v.first-1,v.second));
			if(v.first-1==n-1) return true;
		}



		if(v.second > 0 && !vis[v.first][v.second-1] && G[v.first][v.second-1]!='#')
		{
			vis[v.first][v.second-1]=true;
			P[v.first][v.second-1] = v;
			Q.push(PII(v.first,v.second-1));
			if(v.first==n-1) return true;
		}


		if(v.second < m-1 && !vis[v.first][v.second+1] && G[v.first][v.second+1]!='#')
		{
			vis[v.first][v.second+1]=true;
			P[v.first][v.second+1] = v;
			Q.push(PII(v.first,v.second+1));
			if(v.first==n-1) return true;
		}
	}
	return false;
}


int cut()
{
	int path = 0;
	while(bfs())
	{
		FR(i,m) 
			if(vis[n-1][i])
			{
				path++;
				PII v = PII(n-1,i);
				while(v!=PII(-1,-1))
				{
					G[v.first][v.second]='#';
					v = P[v.first][v.second];
				}
				break;
			}
	}
	return path;
}


int main()
{
	ifstream cin("a.in");
	ofstream fout("a.out");
	int T;cin>>T;
	FOR(_,1,T+1)
	{
		int b;cin>>m>>n>>b;
		CLR(G,'#');
		FR(i,n) FR(j,m) G[i][j]='.';
		FR(i,b)
		{
			int x0,y0,x1,y1;cin>>x0>>y0>>x1>>y1;
			FOR(x,x0,x1+1) FOR(y,y0,y1+1) G[y][x]='#';
		}
		fout<<"Case #"<<_<<": ";
		fout<<cut()<<endl;
	}
}