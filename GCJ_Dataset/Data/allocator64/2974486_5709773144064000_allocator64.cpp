#include <stdio.h>
#include <algorithm>

namespace {

double X, F, C;
double ans = 1e9;

double check(int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += C / (2 + i * F);
	sum += X / (2 + n * F);
	if (sum < ans)
		ans = sum;
	return sum;
}

}

int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; ++test) {
		
		scanf("%lf%lf%lf", &C, &F, &X);

		ans = 1e9;
		int l = 0;
		int r = 1e7;

		while (r - l > 10) {
			int t1 = l + (r - l) / 3;
			int t2 = l + 2 * (r - l) / 3;

			if (check(t1) < check(t2))
				r = t2;
			else
				l = t1;
		}

		for (int i = std::max(l - 1, 0); i <= r + 1; ++i)
			check(i);

		printf("Case #%d: %.10lf\n", test + 1, ans);
	}
	return 0;
}