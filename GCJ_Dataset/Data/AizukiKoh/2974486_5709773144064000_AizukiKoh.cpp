#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

double xTime(double x, double cps) {
	return x / cps;
}

double solve(double c, double f, double x, double cps) {
	if (x / cps < (c / cps + x / (cps + f))) {
		return x / cps;
	} else {
		return c / cps + solve(c, f, x, cps + f);
	}
}

void outputAnswer(int x, double ans) {
	cout << "Case #" << fixed << setprecision(7) << x << ": " << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	double c = 1.0; //farm cost
	double f = 1.0; //farm/sec
	double x = 1.0; //target
	double time; //time
	double cps = 2.0; //producing cookie/second

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> c >> f >> x;
		if (x <= c) {
			time = x / cps;
		} else {
			time = solve(c, f, x, cps);
		}
		outputAnswer(i+1, time);
	}
	cout.flush();
	return 0;
}
