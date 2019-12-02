#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int a[16],b[16],count[16],ans,num,t,i,j,ra,rb;
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&ra);
		for(j=0;j<16;j++) scanf("%d",&a[j]);
		scanf("%d",&rb);
		for(j=0;j<16;j++) scanf("%d",&b[j]);
		ans=0;
		memset(count,0,sizeof(count));
		for(j=0;j<4;j++){
			count[a[4*(ra-1)+j]-1]++;
			count[b[4*(rb-1)+j]-1]++;
		}
		for(j=0;j<16;j++) if(count[j]==2) ans++,num=j+1;
		if(ans==0) printf("Case #%d: Volunteer cheated!\n",i);
		else if(ans==1) printf("Case #%d: %d\n",i,num);
		else printf("Case #%d: Bad magician!\n",i);
	}
	return 0;
}