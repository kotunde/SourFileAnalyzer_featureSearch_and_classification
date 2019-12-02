#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
int n,s,p,T,ans;
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		scanf("%d%d%d",&n,&s,&p);
		ans=0;
		for(int j=1,x;j<=n;++j){
			scanf("%d",&x);
			if(x>=p*3-2)++ans;
			else if(x>=max(p*3-4,p)&&s){++ans;--s;}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
