#include <stdio.h>
#include <string.h>
#include <algorithm>

const int PROB_NUM=3;

typedef std::pair<int,int> P;

P sor[1000];
int arr[1000];
int loc[1000];

void pre_process()
{

}

void process()
{
	int c=0,t,p,n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&sor[i].first);
	for(i=0;i<n;i++)
		sor[i].second=i;
	std::sort(sor,sor+n);
	for(i=0;i<n;i++)
		arr[sor[i].second]=i;
	for(i=0;i<n;i++)
		loc[i]=sor[i].second;
	for(i=0;i<n;i++)
	{
		t=10000;
		for(j=0;j<n-i;j++)
		{
			if(arr[j]<t)
			{
				t=arr[j];
				p=j;
			}
		}
		c+=p<n-i-1-p?p:n-i-1-p;
		for(j=p;j<n-i-1;j++)
			arr[j]=arr[j+1];
	}
	printf("%d\n",c);
}

int main()
{
	char in[10]="0.in";
	char out[10]="0.out";
	in[0]=PROB_NUM+'0';
	out[0]=PROB_NUM+'0';
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	pre_process();
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}