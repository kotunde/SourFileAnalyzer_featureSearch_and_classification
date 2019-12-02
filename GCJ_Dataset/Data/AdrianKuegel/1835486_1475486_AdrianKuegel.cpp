#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

int l[1000], p[1000];

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d", &l[i]);
		for (int i=0; i<n; ++i)
			scanf("%d", &p[i]);
		printf("Case #%d:", scen);
		for (int i=0; i<n; ++i)
		{
			int best = -1, ind;
			for (int j=0; j<n; ++j)
				if (l[j] >= 0 && p[j] > best) {
					best = p[j];
					ind = j;
				}
			l[ind] = -1;
			printf(" %d", ind);
		}
		puts("");
	}
	return 0;
}
