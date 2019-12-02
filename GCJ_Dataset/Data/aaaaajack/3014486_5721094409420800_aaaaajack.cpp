#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
int main(){
	int t,c,n,rev,i,j,ans;
	pair<int,int> a[2000];
	scanf("%d",&t);
	for(c=1;c<=t;c++){
		scanf("%d",&n);
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i].first);
			a[i].second=i;
		}
		sort(a,a+n);
		for(i=n-1;i>=0;i--){
			rev=0;
			for(j=i+1;j<n;j++){
				if(a[i].second>a[j].second) rev++;
			}
			if(rev*2<n-1-i) ans+=rev;
			else ans+=n-1-i-rev;
		}
		printf("Case #%d: %d\n",c,ans);
	}
	return 0;
}