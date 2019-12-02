#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

//BEGINTEMPLATE_BY_ACRUSH_TOPCODER
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(
const double pi=acos(-1.0);//NOTES:pi
const double eps=1e-11;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
typedef pair<int,int> ipair;//NOTES:ipair
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase(
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase(
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter(
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase(
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase(
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}//NOTES:toString(
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
int64 toInt64(string s){int64 r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt64(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
//ENDTEMPLATE_BY_ACRUSH_TOPCODER

string __filename;
int __mod=1,__key=0;

string GetInputFilename()
{
	return __filename+".in";
}
string GetOutputFilename()
{
	if (LENGTH(__filename)<=1)
		return "";
	if (__mod==1)
		return __filename+".out";
	string a=toString(__key);
	return __filename+"_"+a+".out";
}
bool isSkipCase(int caseId)
{
	return caseId%__mod!=__key;
}

const int maxs=300+5;
const int maxnodes=maxs*maxs*4;

int n;
int edge[maxnodes];
int ID[maxs*2][maxs*2];
int d[maxnodes],g[maxnodes][6];
int a[maxnodes];
int father[maxnodes];
int c1[maxnodes];
int pos[maxnodes];
bool is_ring[20000];
bool is_fork[20000];

void add(int a,int b)
{
	g[a][d[a]++]=b;
	g[b][d[b]++]=a;
}
void build(int s)
{
	memset(d,0,sizeof(d));
	memset(ID,255,sizeof(ID));
	n=0;
	for (int i=1;i<=s+s-1;i++)
	{
		int minj=(i<=s)?1:(i-s+1);
		int maxj=(i>=s)?(s+s-1):(s+i-1);
		for (int j=minj;j<=maxj;j++) ID[i][j]=(n++);
	}
	memset(edge,0,sizeof(edge));
	for (int i=1;i<=s+s-1;i++)
	{
		int minj=(i<=s)?1:(i-s+1);
		int maxj=(i>=s)?(s+s-1):(s+i-1);
		for (int j=minj;j<=maxj;j++)
		{
			if (i==1 || i==s+s-1) edge[ID[i][j]]++;
			if (j==minj) edge[ID[i][j]]++;
			if (j==maxj) edge[ID[i][j]]++;
			if (i==s)
			{
				if (j==minj) edge[ID[i][j]]++;
				if (j==maxj) edge[ID[i][j]]++;
			}
		}
		for (int j=minj;j<maxj;j++)
			add(ID[i][j],ID[i][j+1]);
		if (i<s+s-1)
			for (int j=minj;j<=maxj;j++)
				if (i<s)
				{
					add(ID[i][j],ID[i+1][j]);
					add(ID[i][j],ID[i+1][j+1]);
				}
				else
				{
					if (j>minj) add(ID[i][j],ID[i+1][j]);
					if (j<maxj) add(ID[i][j],ID[i+1][j+1]);
				}
	}
}
int getfather(int p)
{
	int t=p;
	for (;father[t]>=0;t=father[t]);
	for (int x=father[p];x>=0;p=x,x=father[p]) father[p]=t;
	return t;
}
void merge(int a,int b)
{
	a=getfather(a);
	b=getfather(b);
	if (a!=b) 
	{
		father[a]=b;
		c1[b]+=c1[a];
	}
}
bool solve(int idx,bool is_r,bool is_f,int counter)
{
	int R=0;
	if (is_r) R|=1;
	if (is_f) R|=4;
	a[idx]=1;
	if (edge[idx]>=2) c1[getfather(idx)]++;
	for (int i=0;i<d[idx];i++)
	{
		int other=g[idx][i];
		if (a[other])
			merge(idx,other);
	}
	if (c1[getfather(idx)]>=2) R|=2;
	if (R>0)
	{
		string s="";
		if (R&2) s+="-bridge";
		if (R&4) s+="-fork";
		if (R&1) s+="-ring";
		printf("%s in move %d\n",s.substr(1).c_str(),counter);
	}
	return (R>0);
}
const int maxnode=100000+5;
const int maxedge=1000000+5;
const int oo=1000000000;

int node,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],Q[maxnode],work[maxnode];

void init(int _node,int _src,int _dest)
{
	node=_node;
	src=_src;
	dest=_dest;
	for (int i=0;i<node;i++) head[i]=-1;
	nedge=0;
}
void addedge(int u,int v,int c1,int c2)
{
	point[nedge]=v,capa[nedge]=c1,flow[nedge]=0,next[nedge]=head[u],head[u]=(nedge++);
	point[nedge]=u,capa[nedge]=c2,flow[nedge]=0,next[nedge]=head[v],head[v]=(nedge++);
}
bool dinic_bfs()
{
	for (int i=0;i<node;i++) dist[i]=-1;
	dist[src]=0;
	int sizeQ=0;
	Q[sizeQ++]=src;
	for (int cl=0;cl<sizeQ;cl++)
		for (int k=Q[cl],i=head[k];i>=0;i=next[i])
			if (flow[i]<capa[i] && dist[point[i]]<0)
			{
				dist[point[i]]=dist[k]+1;
				Q[sizeQ++]=point[i];
			}
	return dist[dest]>=0;
}
int dinic_dfs(int x,int exp)
{
	if (x==dest) return exp;
	int res=0;
	for (int &i=work[x];i>=0;i=next[i])
	{
		int v=point[i],tmp;
		if (flow[i]<capa[i] && dist[v]==dist[x]+1 && (tmp=dinic_dfs(v,min(exp,capa[i]-flow[i])))>0)
		{
			flow[i]+=tmp;
			flow[i^1]-=tmp;
			res+=tmp;
			exp-=tmp;
			if (exp==0) break;
		}
	}
	return res;
}
int dinic_flow()
{
	int result=0;
	while (dinic_bfs())
	{
		for (int i=0;i<node;i++) work[i]=head[i];
		result+=dinic_dfs(src,oo);
	}
	return result;
}
bool solve_fork(int M)
{
	M++;
	init(M+M+1,0,M+M);
	for (int i=0;i<M;i++)
		addedge(i,i+M,1,0);
	memset(a,255,sizeof(a));
	for (int i=0;i<M;i++) if (pos[i]>=0)
	{
		int idx=pos[i];
		a[idx]=i;
		for (int k=0;k<d[idx];k++)
		{
			int other=g[idx][k];
			if (a[other]<0) continue;
			addedge(a[idx]+M,a[other],1,0);
			addedge(a[other]+M,a[idx],1,0);
		}
	}
	for (int i=0;i<n;i++) if (a[i]>=0 && edge[i]==1)
		addedge(a[i]+M,M+M,1,0);
	for (int i=0;i<n;i++) if (a[i]>=0 && edge[i]==1)
	{
		src=a[i]+M;
		for (int j=0;j<nedge;j++) flow[j]=0;
		int ff=dinic_flow();
		if (ff>=3) 
			return true;
	}
	return false;
}
int main(int argc,char **args)
{
//	__filename="B";
//	__filename="B-small-attempt0";
//	__filename="B-small-attempt1";
//	__filename="B-small-attempt2";
//	__filename="B-small-attempt3";
	__filename="B-small-attempt7";
//	__filename="B-large";
	if (argc==1)
	{
		__mod=1;
		__key=0;
	}
	else
	{
		if (argc!=3) { printf("bad arguments\n"); return 0; }
		__mod=atoi(args[1]);
		__key=atoi(args[2]);
	}
	freopen(GetInputFilename().c_str(),"r",stdin);
	if (GetOutputFilename()!="") freopen(GetOutputFilename().c_str(),"w",stdout);
	int testcase;
	cin>>testcase;
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		int s,m;
		cin>>s>>m;
		build(s);
		printf("Case #%d: ",caseId);
		memset(a,0,sizeof(a));
		for (int i=0;i<m;i++)
		{
			int x0,y0;
			scanf("%d%d",&x0,&y0);
			pos[i]=-1;
			if (x0<0 || y0<0 || x0>=maxs*2 || y0>=maxs*2) continue;
			int idx=ID[x0][y0];
			if (idx<0) continue;
			if (a[idx]) continue;
			pos[i]=idx;
			a[idx]=1;
		}
		memset(father,255,sizeof(father));
		memset(c1,0,sizeof(c1));
		for (int i=0;i<=n;i++) c1[i]=(a[i])?0:1;
		c1[n]=1;
		for (int i=0;i<n;i++) if (!a[i]) 
			for (int j=0;j<d[i];j++) if (!a[g[i][j]])
				merge(i,g[i][j]);
		for (int i=0;i<n;i++) if (!a[i] && edge[i]>0)
			merge(n,i);
		int total=0;
		for (int i=0;i<m;i++) if (pos[i]>=0) total++;
		for (int i=m-1;i>=0;i--) if (pos[i]>=0)
		{
			int idx=pos[i];
			is_ring[i]=(c1[getfather(n)]!=(n+1)-total);
			total--;
			a[idx]=0;
			c1[getfather(idx)]++;
			if (edge[idx]>0)
				merge(idx,n);
			for (int j=0;j<d[idx];j++)
			{
				int other=g[idx][j];
				if (!a[other])
					merge(other,idx);
			}
		}
		int H=0,T=m;
		for (;H+1<T;)
		{
			int M=(H+T)/2;
			if (solve_fork(M))
				T=M;
			else
				H=M;
		}
		memset(is_fork,false,sizeof(is_fork));
		for (int i=T;i<m;i++) is_fork[i]=true;
		memset(a,0,sizeof(a));
		memset(father,255,sizeof(father));
		memset(c1,0,sizeof(c1));
		bool done=false;
		for (int i=0;i<m;i++) if (pos[i]>=0)
		{
			int idx=pos[i];
			if (solve(idx,is_ring[i],is_fork[i],i+1))
			{
				done=true;
				break;
			}
		}
		if (!done)
			printf("none\n");
		fflush(stdout);
	}
	return 0;
}