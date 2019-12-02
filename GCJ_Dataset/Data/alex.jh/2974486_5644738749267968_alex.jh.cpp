#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
using namespace std;

int n;
double w1[11], w2[11];
int dp[1<<20];

int solve1(int mask) {
	if (mask==0) return 0;
	if (dp[mask]>=0) return dp[mask];
	
	int tmp = 0;
	
	for (int i=0; i<n; i++) {
		if (mask&(1<<i)) {
			bool exist = 0;
			for (int j=n; j<2*n; j++) {
				if (mask&(1<<j)) {
					if (w2[j-n]>w1[i]) {
						exist = 1;
						tmp = max(tmp, solve1(mask - (1<<i) - (1<<j)));
					}
				}
			}
			if (!exist) {
				int p = -1;
				double w = 0.0;
				for (int j=n; j<2*n; j++) {
					if (mask&(1<<j)) {
						if (w2[j-n]>w) {
							p = j;
							w = w2[j-n];
						}
					}
				}
				tmp = max(tmp, 1 + solve1(mask - (1<<i) - (1<<p)));
			}
		}
	}
	
	dp[mask] = tmp;
	
	return tmp;
}

int solve2(int mask) {
	if (mask==0) return 0;
	if (dp[mask]>=0) return dp[mask];
	
	int tmp = 0;
	
	for (int i=0; i<n; i++) {
		if (mask&(1<<i)) {
			bool exist = 0;
			int p = -1;
			double w = 100.0;
			for (int j=n; j<2*n; j++) {
				if (mask&(1<<j)) {
					if (w2[j-n]>w1[i]) {
						if (w2[j-n]<w) {
							p = j;
							w = w2[j-n];
							exist = 1;
						}
					}
				}
			}
			if (!exist) {
				int p = -1;
				double w = 10.0;
				for (int j=n; j<2*n; j++) {
					if (mask&(1<<j)) {
						if (w2[j-n]<w) {
							p = j;
							w = w2[j-n];
						}
					}
				}
				tmp = max(tmp, 1 + solve2(mask - (1<<i) - (1<<p)));
			}
			else {
				tmp = max(tmp, solve2(mask - (1<<i) - (1<<p)));
			}
		}
	}
	
	dp[mask] = tmp;
	
	return tmp;
}

int main() {
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t;
	cin>>t;
	int cas = 1;
	while (t--) {
		cin>>n;
		for (int i=0; i<n; i++) cin>>w1[i];
		for (int i=0; i<n; i++) cin>>w2[i];
		
		for (int i=0; i<(1<<2*n); i++) dp[i] = -1;
		
		int t1 = solve1((1<<(2*n))-1);
		
		for (int i=0; i<(1<<2*n); i++) dp[i] = -1;
		
		int t2 = solve2((1<<(2*n))-1);
		
		printf("Case #%d: %d %d\n", cas, t1, t2);
		
		cas++;
	}
 	
	return 0;
}

