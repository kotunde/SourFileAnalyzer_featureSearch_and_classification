#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
using namespace std;
double X[100002];
int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,A,B;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d%d",&A,&B);
        for(int i=0;i<A;i++) scanf("%lf",&X[i]);
        double ans=B+2;
        double p=1.0;
        for(int i=0;i<=A;i++){
            ans=min(ans,p*(A-i+B-i+1)+(1.0-p)*(A-i+B-i+1+B+1));
            p=p*X[i];
        }
        printf("Case #%d: %.8lf\n",I,ans);
    }
    return 0;
}
