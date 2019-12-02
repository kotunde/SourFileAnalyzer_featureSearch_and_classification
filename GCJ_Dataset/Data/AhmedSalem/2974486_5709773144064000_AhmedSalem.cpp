#include<bits/stdc++.h>
using namespace std ;

double C,F,X;

double solve(){
    double cookies = 0,tim = 0, rate = 2;
    double ret = 1e18;
    for (int buy=0;buy<=100000;buy++){
        ret = min(ret, tim + X / rate);
        tim += C / rate;
        rate += F;
    }
    return ret;
}

int main(){
    freopen("cookie.in","r",stdin);
    freopen("cookie.out","w",stdout);
    int c,c2;
    int tests;
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++){
        printf("Case #%d: ",test);
        
        
        scanf("%lf%lf%lf",&C,&F,&X);
        double ret = solve();
        printf("%.10lf\n",ret);
        
            
    }
    
    
    return 0;
    
}
