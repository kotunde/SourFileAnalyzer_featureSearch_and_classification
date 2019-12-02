#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <sstream>
#include <iomanip>
#include <memory.h>

using namespace std;

const char* inputFile = "B-small-attempt0.in";
const char* outputFile = "B-small-attempt0.out";

string solveTest() {
	double C, F, X;
	cin >> C >> F >> X;

	double buildTime = 0.0;
	double totalTime = 0.0;
	double bestTime = numeric_limits<double>::max();
	for (size_t n = 0; n < 5000000; ++n) {
		totalTime = buildTime + (X / (2 + n * F));
		bestTime = min(bestTime, totalTime);
		buildTime += C / (2 + n * F);
	}

	stringstream ss;
	ss << fixed << setprecision(7) << bestTime;
	return ss.str();
}

int main() {
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	size_t T;
	scanf("%d\n", &T);
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		string verdict = solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
