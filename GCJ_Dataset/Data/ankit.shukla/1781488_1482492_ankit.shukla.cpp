#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second
using namespace std;

typedef pair<int,int> pii;

double t[2001],x[2001],a[200];
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int T,N,A;
    double D;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%lf%d%d",&D,&N,&A);
        for(int i=0;i<N;i++) scanf("%lf%lf",&t[i],&x[i]);
        printf("Case #%d: \n",I);
        for(int i=0;i<A;i++){
            scanf("%lf",&a[i]);
            double ans;
            if(N>1){
                if(x[0]>=D)                     ans=sqrt(2.0*D/a[i]);
                else{
                    double tt=(D-x[0])/(x[1]-x[0]) * t[1];
                    double d=0.5*a[i]*(tt*tt);
                    /*if(d<=x[1] || x[0]>=D){
                        ans=sqrt(2.0*D/a[i]);
                    }
                    else{
                        double xx=min(D,x[1]);
                        double v=sqrt(2.0*a[i]*xx);
                        ans=(sqrt(v*v+2.0*a[i]*(D-xx))-v)/a[i];
                        ans+=(xx-x[0])/(x[1]-x[0]) * t[1];
                    }*/
                    if(d<D){
                        ans=sqrt(2.0*D/a[i]);
                    }
                    else{
                        ans=tt;
                    }
                }
            }
            else{
                ans=sqrt(2.0*D/a[i]);
            }
            printf("%.8lf\n",ans);
        }   
    }
    return 0;
}

    
