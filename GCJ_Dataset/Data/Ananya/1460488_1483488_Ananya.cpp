#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main ()
{
	int T, tc, i, j;
	int A, B, c;
	int n, rn, lowpow, highpow;
	set<int> rep;
	scanf("%d",&T);
	
	for ( tc = 1; tc <= T; tc++ )
	{
		scanf("%d %d",&A,&B);
		c = 0;
		
		for ( i = A; i < B; i++ )
		{
			lowpow = 10;
			highpow = pow(10.0,(int)(log(i)/log(10))*1.0);
			rep.clear();
			
			while ( i > lowpow )
			{
				n = (i%lowpow)*highpow + i/lowpow;
				if ( i < n && n <= B && rep.count(n) == 0 ) c++;
				rep.insert(n);
				lowpow *= 10;
				highpow /= 10;
			}
		}
		
		printf("Case #%d: %d\n",tc,c);
	}
}