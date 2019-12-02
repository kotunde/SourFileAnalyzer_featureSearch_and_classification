#include <stdio.h>
#include <set>

typedef std::set<double> S;

S s;
double nao[1000];
double ken[1000];

int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	S::iterator p;
	int t,n,y,z,i,j;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%lf",&nao[j]);
		for(j=0;j<n;j++)
			scanf("%lf",&ken[j]);
		y=0;
		z=0;
		for(j=0;j<n;j++)
			s.insert(nao[j]);
		for(j=0;j<n;j++)
		{
			p=s.lower_bound(ken[j]);
			if(p==s.end())
				p=s.begin();
			if(*p>ken[j])
				y++;
			s.erase(p);
		}
		for(j=0;j<n;j++)
			s.insert(ken[j]);
		for(j=0;j<n;j++)
		{
			p=s.lower_bound(nao[j]);
			if(p==s.end())
				p=s.begin();
			if(*p<nao[j])
				z++;
			s.erase(p);
		}
		printf("%d %d\n",y,z);
	}
	return 0;
}