#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <iomanip>

#include <algorithm>
#include <cmath>
#include <ctime>

#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define PROBLEM "B"

double getTime(double c, double f, double x, long long n) {
    double res = 0;
    for (long long i = 0; i < n; ++i) {
        res += c / (2 + i * f);
    }
    res += x / (2 + n * f);
    return res;
}

void solveTestCase() {
    double c, f, x;
    cin >> c >> f >> x;
    long long low  = 0;
    long long high = 1000000;// numeric_limits<long long>::max();
    while (low < high - 10) {
        long long m1 = low + (high - low) / 3;
        long long m2 = low + (high - low) * 2 / 3;
        double res1 = getTime(c, f, x, m1);
        double res2 = getTime(c, f, x, m2);
        if (res1 < res2) {
            high = m2;
        } else {
            low = m1;
        }
    }
    double m = numeric_limits<double>::max();
    for (long long i = max(0LL, low - 20); i < high + 20; ++i) {
        m = min(m, getTime(c, f, x, i));
    }
    printf("%.10lf\n", m);
}

int main() {
    freopen("input_" PROBLEM ".txt", "rt", stdin); //-V530
    freopen("output.txt", "wt", stdout); //-V530
    int num_tests;
    cin >> num_tests;
    for (int i = 1; i <= num_tests; ++i) {
        cout << "Case #" << i << ": ";
        solveTestCase();
    }
    return 0;
}