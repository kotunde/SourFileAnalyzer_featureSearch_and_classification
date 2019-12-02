#include<bits/stdc++.h>
using namespace std;
#define s(x) scanf("%d",&x)
#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);
double c,f,x;
inline void gett(int k,double& t){
    double ret=0.0;
    double div=2.0;
    for(int farm=1;farm<=k;++farm){
        ret+=(c/div);
        div+=f;
    }
    t=ret+(x/div);
}
int main(){
    READ("2.in");
    WRITE("2.out");
    int t;cin>>t;
    for(int caseid=1;caseid<=t;++caseid){
        scanf("%lf%lf%lf",&c,&f,&x);
        printf("Case #%d: ",caseid);
        double k=x/c-2.0/f-1.0;
        if(x<=c || k<0.0){printf("%.7lf\n",(x/2.0));continue;}
        double t;
        gett((1.0*floor(k)==k?ceil(k+0.1):ceil(k)),t);
        printf("%.7lf\n",t);
    }
}
