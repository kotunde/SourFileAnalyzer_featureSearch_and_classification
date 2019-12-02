#include <stdio.h>

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	double m,r,s,c,f,x;
	int t,i;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		scanf("%lf%lf%lf",&c,&f,&x);
		m=x/2.0;
		r=2.0;
		s=0.0;
		if(c<x)
		{
			while(s<=m)
			{
				m=x/r+s<m?x/r+s:m;
				s+=c/r;
				r+=f;
			}
		}
		printf("%.8lf\n",m);
	}
	return 0;
}