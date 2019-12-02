#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

// const char* inputFile = "file.in";
// const char* outputFile = "file.out";

const char* inputFile = "D-small-attempt0.in";
const char* outputFile = "D-small-attempt0.out";

class Solver {
public:
	Solver() {
	}

	string solveTest() {
		cin >> m >> n;
		s.resize(m);
		for (int i = 0; i < m; ++i) {
			cin >> s[i];
		}

		int worstNodesNumber = 0;
		int count = 0;
		stupidSolve(worstNodesNumber, count);
		stringstream ss;
		ss << worstNodesNumber << " " << count;
		return ss.str();
	}

	void stupidSolve(int &worstNodesNumber, int &count) {
		vector<int> distribution(m);
		dfs(0, distribution, worstNodesNumber, count);
	}

	int findServerNodesNumber(vector<int> serverStrings) {
		if (serverStrings.empty()) {
			return 0;
		}
		std::set<string> prefixes;
		for (int i = 0; i < serverStrings.size(); ++i) {
			string prefix = "";
			string serverString = s[serverStrings[i]];
			// DB(serverStrings[i]);
			for (size_t j = 0; j < serverString.length(); ++j) {
				prefix += serverString[j];
				// DB(prefix);
				prefixes.insert(prefix);
			}
		}
		return prefixes.size() + 1;
	}

	int findNodesNumber(vector<int> distribution) {
		// DB("------")
		vector< vector<int> > serversStrings(n);
		for (int i = 0; i < m; ++i) {
			// DB(i);
			// DB(distribution[i]);
			serversStrings[distribution[i]].push_back(i);
		}

		int nodesNumber = 0;
		for (int i = 0; i < n; ++i) {
			nodesNumber += findServerNodesNumber(serversStrings[i]);
		}
		return nodesNumber;
	}

	void dfs(int currentString, vector<int> &distribution, int &worstNodesNumber, int &count) {
		if (currentString == m) {
			int nodesNumber = findNodesNumber(distribution);
			// DB(nodesNumber)
			if (nodesNumber > worstNodesNumber) {
				worstNodesNumber = nodesNumber;
				count = 0;
			}
			if (nodesNumber == worstNodesNumber) {
				++count;
			}
			return;
		}

		for (int i = 0; i < n; ++i) {
			distribution[currentString] = i;
			dfs(currentString + 1, distribution, worstNodesNumber, count);
		}
	}

	int n, m;
	vector<string> s;
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
