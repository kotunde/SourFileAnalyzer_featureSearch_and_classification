#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
using namespace std;
int a[4][4],b[4][4];
int main()
{
    int T,ncase=0,i;
    double c,f,x;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&c,&f,&x);
        double ans=x/2.0,t=0.0;
        for(i=1;;i++){
            if(i>1) t+=c/(2+(i-1)*f)+x/(2+i*f)-x/(2+(i-1)*f);
            else t=c/2+x/(2+f);
            if(t>ans) break;
            else ans=t;
        }
        printf("Case #%d: %.7lf\n", ++ncase, ans);
    }
    return 0;
}
/*
3,1,2
1,2,3,4,5
5,4,3,2,1
*/
