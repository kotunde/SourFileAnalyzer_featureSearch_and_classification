#include <stdio.h>

const int PROB_NUM = 1 ;

char arr[100][101];

inline int ab(int a)
{
	return a<0?-a:a;
}

void process()
{
	char p,q;
	int n,a=0,b=0,s=0,c,d,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",arr[i]);
	if(n==2)
	{
		while(arr[0][a]||arr[1][b])
		{
			if(!arr[0][a]||!arr[1][b])
			{
				printf("Fegla Won\n");
				return;
			}
			c=1;
			d=1;
			p=arr[0][a++];
			q=arr[1][b++];
			if(p!=q)
			{
				printf("Fegla Won\n");
				return;
			}
			while(arr[0][a]&&arr[0][a]==p)
			{
				a++;
				c++;
			}
			while(arr[1][b]&&arr[1][b]==q)
			{
				b++;
				d++;
			}
			s+=ab(c-d);
		}
		printf("%d\n",s);
	}
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