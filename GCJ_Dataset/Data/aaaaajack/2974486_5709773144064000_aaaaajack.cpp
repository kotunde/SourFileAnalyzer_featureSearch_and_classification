#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int r,t,farm,i;
	double X,F,C,ans;
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-small.out","w",stdout);
	scanf("%d",&t);
	for(r=1;r<=t;r++){
		scanf("%lf%lf%lf",&C,&F,&X);
		farm=(int)ceil(X/C-1-2.0/F);
		if(farm<0) farm=0;
		ans=0;
		for(i=0;i<farm;i++) ans+=C/(i*F+2);
		ans+=X/(farm*F+2);
		printf("Case #%d: %.7f\n",r,ans);
	}
	return 0;
}