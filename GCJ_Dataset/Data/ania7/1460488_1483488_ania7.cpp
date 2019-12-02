#include <cstdio>
#include <set>
using namespace std;

#define maxn 2500100

int q;
int N[maxn], M[maxn];
set<pair<int,int> > S;
int pw[11];

void init()
{
	pw[0] = 1;
	for(int i = 1; i <= 7; i++) pw[i] = pw[i-1] * 10;
	for(int l1 = 1; l1 <= 6; l1++) for(int l2 = 1; l2+l1 <= 7; l2++)
		for(int a1 = pw[l1-1]; a1 < pw[l1]; a1++)
			for(int a2 = pw[l2-1]; a2 < pw[l2]; a2++)
			{
				int nn = a1 * pw[l2] + a2, mm = a2 * pw[l1] + a1;
				if(nn < mm && mm <= 2000000 && S.find(make_pair(nn,mm)) == S.end())
				{
					N[q] = nn;
					M[q] = mm;
					q++;
					S.insert(make_pair(nn,mm));
				}
			}
	//printf("q = %d\n", q);
}

int test()
{
	int A,B,res=0;
	scanf("%d%d", &A, &B);
	for(int i = 0; i < q; i++) if(N[i] >= A && M[i] <= B)
	{
		//printf("%d %d\n", N[i], M[i]);
		res++;
	}
	return res;
}

int main()
{
	init();
	int tt;
	scanf("%d", &tt);
	for(int t=1;t<=tt;t++) printf("Case #%d: %d\n", t, test());
}
