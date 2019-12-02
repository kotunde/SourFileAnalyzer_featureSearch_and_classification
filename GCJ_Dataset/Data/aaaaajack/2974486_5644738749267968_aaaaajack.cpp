#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	//freopen("D-small-attempt0.in","r",stdin);
	//freopen("D-small.out","w",stdout);
	int r,t,i,j,n,p,q;
	double a[1010],b[1010];
	scanf("%d",&t);
	for(r=1;r<=t;r++){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%lf",&a[i]);
		for(i=0;i<n;i++) scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		for(i=0;i<=n;i++){
			for(j=0;j<i;j++){
				if(a[n-i+j]<b[j]) break;
			}
			if(j==i) p=i;
		}
		for(i=0;i<=n;i++){
			for(j=0;j<i;j++){
				if(a[j]>b[n-i+j]) break;
			}
			if(j==i) q=i;
		}
		printf("Case #%d: %d %d\n",r,p,n-q);
	}
	return 0;
}