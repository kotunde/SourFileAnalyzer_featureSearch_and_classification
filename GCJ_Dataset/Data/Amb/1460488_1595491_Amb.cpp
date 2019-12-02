#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int val[105];
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B_small.out", "w", stdout);
	
	int t, cas=0;
	scanf("%d",&t);
	while(t--){
		int n, s, p;
		scanf("%d%d%d", &n, &s, &p);
		int pcnt = 0, bcnt = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &val[i]);
			if(val[i]>=max(0,p-1)+max(0,p-1)+p){
				pcnt++;
			}else if(val[i]>=max(0,p-2)+max(0,p-2)+p){
				bcnt++;
			}
		}
		int ans = pcnt + min(bcnt, s);
		printf("Case #%d: %d\n",++cas,ans);
	}
}