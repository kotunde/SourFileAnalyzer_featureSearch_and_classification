#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;

int vis[20];

int main()
{
    int t,r,i,j,k;

    freopen("a.in","r",stdin);
    freopen("a.txt","w",stdout);
    int ii=0;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&r);
	memset(vis,0,sizeof(vis));

	for(i=1;i<=4;i++)
	{
	    for(j=1;j<=4;j++)
	    {
		scanf("%d",&k);
		if(i==r)
		    vis[k]++;
	    }
	}
	scanf("%d",&r);

	for(i=1;i<=4;i++)
	{
	    for(j=1;j<=4;j++)
	    {
		scanf("%d",&k);
		if(i==r)
		    vis[k]++;
	    }
	}
	int cnt=0;

	for(i=1;i<=16;i++)if(vis[i]==2)
	    cnt++,j=i;
	printf("Case #%d: ",++ii);
	if(cnt==1)
	    printf("%d\n",j);
	else if(cnt>1)
	    puts("Bad magician!");
	else
	    puts("Volunteer cheated!");
    }
}
