#include <cstdio>

int test()
{
	int N, S, P, Q, K, res = 0;
	scanf("%d%d%d", &N, &S, &P);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &Q);
		K = Q / 3;
		if(Q%3 == 0)
		{
			if(K >= P) res++;
			else if(K-1 >= 0 && K+1 <= 10 && K+1 >= P && S > 0)
			{
				res++;
				S--;
			}
		}
		else if(Q%3 == 1)
		{
			if(K+1 <= 10 && K+1 >= P) res++;
		}
		else
		{
			if(K+1 <= 10 && K+1 >= P) res++;
			else if(K+2 <= 10 && K+2 >= P && S > 0)
			{
				res++;
				S--;
			}
		}
	}
	return res;
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for(int t=1;t<=tt;t++)
	{
		printf("Case #%d: %d\n", t, test());
	}
}
