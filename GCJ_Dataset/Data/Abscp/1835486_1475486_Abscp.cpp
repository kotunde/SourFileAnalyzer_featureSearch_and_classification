#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,t[22],c[22],p[22];
bool cmp(int a,int b){
	return p[a]>p[b]||(p[a]==p[b]&&a<b); 
} 
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&t[i]); 
		for(int i=0;i<n;++i){ 
			scanf("%d",&p[i]);
			c[i]=i;
		} 
		sort(c,c+n,cmp);
		printf("Case #%d:",tt);
		for(int i=0;i<n;++i)printf(" %d",c[i]);
		printf("\n"); 
	} 
	return 0; 
}
