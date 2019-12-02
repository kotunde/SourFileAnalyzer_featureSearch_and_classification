#include <cstdio>
#include <algorithm>

using namespace std;

#define For(i,a,b) for(int i = a; i < b; i++)

double nextDouble() {
	double x;
	scanf("%lf", &x);
	return x;
}

int nextInt() {
	int x;
	scanf("%d", &x);
	return x;
}

double solve(double c, double f, double x, double rate) {
	if (rate > 1e5)
		return x / rate;
	return min(x/rate, c/rate + solve(c, f, x, rate + f));
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tt = nextInt();
	For (t, 1, tt+1) {
		double c = nextDouble();
		double f = nextDouble();
		double x = nextDouble();
		double res = solve(c, f, x, 2);
		printf("Case #%d: %lf\n", t, res);
	}
	return 0;
}
