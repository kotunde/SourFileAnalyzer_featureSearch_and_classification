#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int flag,n,l[10010],x[10010],xx,f[10010];
int main(){
	freopen("temp.in","r",stdin);
	freopen("temm.out","w",stdout);
	int T;scanf("%d",&T);
	for(int t=1;t<=T;++t){
		flag=0;
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&l[i]);
		if(l[1]>=x[1])f[1]=x[1];
		for(int i=2;i<=n;++i)
			for(int j=1;j<i;++j)
				if(x[i]-x[j]<=f[j])
					f[i]=min(max(f[i],x[i]-x[j]),l[i]);
		scanf("%d",&xx);
		for(int i=1;i<=n;++i)if(x[i]+f[i]>=xx)flag=1;
		printf("Case #%d: ",t);
		if(flag)printf("YES");else printf("NO");
		printf("\n");
	}
	return 0;
}
