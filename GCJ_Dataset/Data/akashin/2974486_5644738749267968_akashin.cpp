#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "D-small-attempt0.in";
const char* outputFile = "D-small-attempt0.out";

class Solver {
public:
	string solveTest() {
		int N;
		cin >> N;
		vector<double> naomi(N), ken(N);

		for (size_t i = 0; i < N; ++i) {
			cin >> naomi[i];
		}
		for (size_t i = 0; i < N; ++i) {
			cin >> ken[i];
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		return to_string(deceitful_war(naomi, ken)) + " " + to_string(war(naomi, ken));
	}

	int war(vector<double> naomi, vector<double> ken) {
		size_t N = naomi.size();
		size_t naomiWins = 0;

		for (size_t i = 0; i < N; ++i) {
			bool canWin = false;
			for (size_t j = 0; j < ken.size(); ++j) {
				if (ken[j] > naomi[i]) {
					canWin = true;
					ken.erase(ken.begin() + j);
					break;
				}
			}
			if (!canWin) {
				++naomiWins;
				ken.erase(ken.begin());
			}
		}
		return naomiWins;
	}

	int deceitful_war(vector<double> naomi, vector<double> ken) {
		size_t N = naomi.size();
		size_t naomiWins = 0;

		for (size_t i = 0; i < N; ++i) {
			if (naomi[i] > ken[0]) {
				++naomiWins;
				ken.erase(ken.begin());
			} else {
				ken.erase(ken.begin() + ken.size() - 1);
			}
		}
		return naomiWins;
	}
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
