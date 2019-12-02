#include <stdio.h>
#include <string.h>

int arr[4][4];
bool mem[17];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	bool f;
	int t,r,n,i,j,k;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		f=1;
		n=0;
		printf("Case #%d: ",i);
		memset(mem,0,sizeof(mem));
		scanf("%d",&r);
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				scanf("%d",&arr[j][k]);
		for(j=0;j<4;j++)
			mem[arr[r-1][j]]=1;
		scanf("%d",&r);
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				scanf("%d",&arr[j][k]);
		for(j=0;j<4;j++)
		{
			if(mem[arr[r-1][j]])
			{
				if(n)
				{
					printf("Bad magician!\n");
					f=0;
					break;
				}
				n=arr[r-1][j];
			}
		}
		if(f)
		{
			if(n)
				printf("%d\n",n);
			else
				printf("Volunteer cheated!\n");
		}
	}
	return 0;
}