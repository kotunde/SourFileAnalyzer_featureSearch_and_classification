#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

ifstream fin("small.in");
ofstream fout("small.out");
//ifstream fin("large.in");
//ofstream fout("large.out");

int n, v[100000], h[100000], l[100000], d;

void solve(int I) {
    fin >> n;
    for (int i = 0; i < n; ++i) {
        h[i] = -1;
        fin >> v[i] >> l[i];
    }
    fin >> d;
    h[0] = v[0];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (h[i] >= v[j] - v[i]) h[j] = max(h[j], min(v[j] - v[i], l[j]));
        }
    }
    for (int i = 0; i < n; ++i) {
        if (h[i] + v[i] >= d) {
            fout << "Case #" << I << ": YES\n";
            return;
        }
    }
    fout << "Case #" << I << ": NO\n";
}

int t;

int main() {
    fin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}