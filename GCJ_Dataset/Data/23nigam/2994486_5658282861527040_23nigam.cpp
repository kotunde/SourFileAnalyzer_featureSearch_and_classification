#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
main()
{
	int cases;
	cin>>cases;
	for(int c1=1;c1<=cases;c1++){
	int a,b,k,ret=0;
	cin>>a>>b>>k;
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if((i&j)<k)
				ret++;
	printf("Case #%d: %d\n",c1,ret);
	}
}