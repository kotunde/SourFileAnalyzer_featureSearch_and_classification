#include <stdio.h>

const int PROB_NUM = 3 ;

void process()
{
	int a,b,k,s=0,i,j;
	scanf("%d%d%d",&a,&b,&k);
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			if((i&j)<k)
				s++;
	printf("%d\n",s);
}

int main()
{
	char in[10]="0.in";
	char out[10]="0.out";
	in[0]=PROB_NUM+'0';
	out[0]=PROB_NUM+'0';
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}