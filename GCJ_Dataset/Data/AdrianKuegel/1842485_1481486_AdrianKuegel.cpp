#include <stdio.h>
#include <algorithm>
using namespace std;

int d[100000], l[100000];
bool reach[100000];
int pos[100000];

int main() {
	int tc,n;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen)
	{
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
		{
			scanf("%d %d", &d[i], &l[i]);
			reach[i] = false;
		}
		reach[n] = false;
		scanf("%d", &d[n]);
		n++;
		reach[0] = true;
		pos[0] = 0;
		for (int i=0; i<n; ++i)
		{
			if (!reach[i]) continue;
		//	printf("%d %d %d\n", i, d[i], pos[i]);
			int upto = min(d[i]-pos[i], l[i])+d[i];
			for (int j=i+1; j<n; ++j)
			{
				if (d[j] > upto)
					break;
				if (!reach[j] || d[i] < pos[j])
				{
					pos[j] = d[i];
					reach[j] = true;
				}
			}
		}
		printf("Case #%d: %s\n", scen, reach[n-1]?"YES":"NO");
	}
	return 0;
}
