#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

int ch[110][26],cnt;

void ins(char *s)
{
	int t=0,c;

	for(int i=0;s[i];i++)
	{
		c=s[i]-'A';
		if(!ch[t][c])
			ch[t][c]=++cnt;
		t=ch[t][c];
	}
}
char s[110][110];
int getnum(vector<int>&V)
{
	cnt=0;
	memset(ch,0,sizeof(ch));
	int i;

	for(i=0;i<V.size();i++)
		ins(s[V[i]]);
	return cnt+1;
}

int M,num;
int bel[20];
vector<int>V[110];

void dfs(int dep,int n,int m)
{
	if(dep==m)
	{
		int i,j,k;
		for(i=0;i<n;i++)
			V[i].clear();
		for(i=0;i<m;i++)
			V[bel[i]].push_back(i);
		for(i=0;i<n;i++)if(V[i].size()==0)
			return;
		int tmp=0;

		for(i=0;i<n;i++)
			tmp+=getnum(V[i]);
		if(tmp>M)
		{
			M=tmp;
			num=1;
		}
		else if(tmp==M)
			num++;
		return;
	}
	for(int i=0;i<n;i++)
		bel[dep]=i,dfs(dep+1,n,m);
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int t,ii=0;
	int n,m,i,j,k;

	cin>>t;

	while(t--)
	{
		cin>>m>>n;

		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		M=-1;

		dfs(0,n,m);
		printf("Case #%d: %d %d\n",++ii,M,num);
	}
}