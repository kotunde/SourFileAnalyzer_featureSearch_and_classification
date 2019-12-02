#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
using namespace std;

const double eps = 1.0e-8;
double best;

void rec(double c, double f, double x, double s, double r, double cur) {
	if (cur>best-eps) return;
	if (s>x-eps) {
		best = cur;
		return;
	}
	
	best = min(best, cur+(x-s)/r);
	if (s>c-eps) rec(c,f,x,s-c,r+f, cur);
	else rec(c,f,x,0,r+f, cur+(c-s)/r);
	
	return;
}

int main() {
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t;
	cin>>t;
	int cas = 1;
	while (t--) {
		double c,f,x;
		cin>>c>>f>>x;
		double s = 0.0;
		double r = 2.0;
		double cur = 0.0;
		best = x/2.0;
		rec(c,f,x,s,r,cur);
		printf("Case #%d: %.12f\n", cas, best);
		cas++;
	}
 	
	return 0;
}

