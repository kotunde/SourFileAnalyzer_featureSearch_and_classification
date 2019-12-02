#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long c;
long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main() 
{
	long long t,p,q,g;
	long double div;
	long long chk,cas=0;
	cin>>t;
	while(t--)
	{
		printf("Case #%d: ",++cas);
		scanf("%Ld/%Ld",&p,&q);
		g=gcd(p,q);
		p/=g;
		q/=g;
		if(p>q || q%2==1)
			printf("impossible");
		else
		{
			long double cl,v;
			long long ans=0;
			cl=log2((double)q);
	//		cout<<cl<<endl;
			if(cl-(long long)cl < 0.00000001)
			{
				v=(long double)p/(long double)q;
				while(v<1)
				{
		//			cout<<v<<" ";
					ans++;
					v*=2;
				}
				printf("%Ld",ans);
			}
			else
				printf("impossible");
		}
		cout<<endl;
	}
	return 0;
}