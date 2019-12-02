#include <iostream>
#include<stdio.h>
#include <algorithm>
#include <stdint.h>
#include <string.h>

using namespace std;

int main()
{
    int t;
    double c,f,x;
    double ans;

    double v;

    freopen("b.in","r",stdin);
    freopen("b.txt","w",stdout);

    int ii=0;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%lf%lf%lf",&c,&f,&x);

	ans=x/2;

	v=2;
	double now=c/2;
	for(int i=1;i<=11000000;i++)
	    ans=min(ans,now+x/(v+f)),v+=f,now+=c/v;
	printf("Case #%d: %.12lf\n",++ii,ans);
    }
}
