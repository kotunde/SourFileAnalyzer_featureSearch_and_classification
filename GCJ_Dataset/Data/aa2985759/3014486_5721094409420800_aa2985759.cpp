#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

int a[1100];

int dfs(int l,int r)
{
	int m=0,i,j,k,pos;
	for(i=l;i<=r;i++)if(m<a[i])
		m=max(m,a[i]),pos=i;
	int can1=1,can2=1;

	for(i=l;i<pos;i++)if(a[i]>a[i+1])
		can1=0;
	for(i=pos;i<r;i++)if(a[i]<a[i+1])
		can2=0;
	if(can1&&can2)
		return 0;
	for(i=l;i<=r;i++)if(m>a[i])
		m=a[i],pos=i;
	int ans=0;
	if(pos-l<r-pos)
	{
		ans=pos-l;
		while(pos>l)
			swap(a[pos],a[pos-1]),pos--;
		return ans+dfs(l+1,r);
	}
	else
	{
		ans=r-pos;
		while(pos<r)
			swap(a[pos],a[pos+1]),pos++;
		return ans+dfs(l,r-1);
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int t,ii=0;
	int n,i,j,k;

	cin>>t;

	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		printf("Case #%d: %d\n",++ii,dfs(0,n-1));
	}
}