#include<bits/stdc++.h>
using namespace std;
#define F(i,n) for(int i=0;i<n;++i)
#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);
double naomi[1000+100],ken[1000+100];
int n;
const double eps=1e-7;
int main(){
    READ("4.in");
    WRITE("4.out");
    int t;cin>>t;
    for(int caseid=1;caseid<=t;++caseid){
        scanf("%d",&n);
        F(i,n)scanf("%lf",&naomi[i]);
        F(i,n)scanf("%lf",&ken[i]);
        sort(naomi,naomi+n);
        sort(ken,ken+n);
        int dscore=0,left=0;
        for(int x=0;x<n;++x)if(naomi[x]>ken[left]){dscore++;left++;}
        int wscore=0,right=n-1;
        for(int x=n-1;x>=0;--x){
            if(naomi[x]>ken[right]){wscore++;}
            else{right--;}
        }
        printf("Case #%d: %d %d\n",caseid,dscore,wscore);
    }
}
