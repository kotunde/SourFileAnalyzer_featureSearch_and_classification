#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
int n,l,r,ans,u[10000000],len[10000000],p[10];
int check(int x){
	u[x]=1;
	int now=x,cnt=0;
	do{
		int t=now%10;now/=10;now+=t*p[len[x]];
		if(len[now]==len[x]&&now>=l&&now<=r){
			u[now]=1;++cnt;
		}
	}while(now!=x);
	ans+=cnt*(cnt-1)/2;
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&n);
	int t=1;
	for(int i=1;i<10000000;++i){
		len[i]=len[i-1];
		if(i==t){++len[i];p[len[i]]=t;t*=10;}
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&l,&r);
		ans=0;memset(u,0,sizeof(u));
		for(int j=l;j<=r;++j)
			if(!u[j])check(j);
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
