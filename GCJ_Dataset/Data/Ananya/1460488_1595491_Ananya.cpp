#include <cstdio>
#include <cmath>
using namespace std;

int N, S, p, c, T, j;
int cursum, curmax, surpmax;
int modToSurp[3] = {1,0,1};

int main ()
{
	scanf("%d",&T);
	
	for ( int tc = 1; tc <= T; tc++ )
	{
		scanf("%d %d %d",&N,&S,&p);
		c = 0;
		
		for ( j = 0; j < N; j++ )
		{
			scanf("%d",&cursum);
			curmax = ceil(cursum/3.0);
			if ( curmax >= p ) { c++; continue; }
			if ( curmax+modToSurp[cursum%3] >= p && S > 0 && cursum != 0 ) { c++; S--; }
		}
		
		printf("Case #%d: %d\n",tc,c);
	}
}