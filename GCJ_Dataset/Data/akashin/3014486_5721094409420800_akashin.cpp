#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cassert>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

// const char* inputFile = "B-large.in";
// const char* outputFile = "B-large.out";

const char* inputFile = "B-small-attempt0.in";
const char* outputFile = "B-small-attempt0.out";

// const char* inputFile = "file.in";
// const char* outputFile = "file.out";

class Solver {
public:
	Solver() {
	}

	string solveTest() {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int lInv = 0;
			int rInv = 0;
			for (int j = 0; j < i; ++j) {
				if (a[j] > a[i]) {
					++lInv;
				}
			}
			for (int j = i + 1; j < n; ++j) {
				if (a[j] > a[i]) {
					++rInv;
				}
			}
			ans += min(lInv, rInv);
		}
		return std::to_string(ans);
	}

	int n;
	vector<int> a;
};

int main() {
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	for (int testNumber = 1; testNumber <= T; ++testNumber) {
		Solver solver;
		string verdict = solver.solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
