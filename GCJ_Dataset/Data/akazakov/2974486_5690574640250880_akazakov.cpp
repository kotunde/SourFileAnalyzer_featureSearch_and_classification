#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

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

#define PROBLEM "C"

inline int bitCount(int n) {
    int res = 0;
    while (n) {
        res += (n & 1);
        n >>= 1;
    }
    return res;
}

queue<pair<int, int>> q;

inline bool checkPosition(int n, int m, int p) {
    char field[20][20] = {2};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            field[i][j] = p & 1;
            p >>= 1;
        }
    }
    pair<int, int> free_cell = make_pair(-1, -1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (field[i][j] == 0 && (
                    field[i - 1][j] == 1 || field[i + 1][j] == 1 ||
                    field[i][j - 1] == 1 || field[i][j + 1] == 1 ||
                    field[i - 1][j - 1] == 1 || field[i - 1][j + 1] ||
                    field[i + 1][j - 1] == 1 || field[i + 1][j + 1])) {
                field[i][j] = 2;
            } else {
                if (field[i][j] == 0) {
                    free_cell = make_pair(i, j);
                }
            }
        }
    }
    if (free_cell == make_pair(-1, -1)) {
        return false;
    }
    // wave
    q.push(free_cell);
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        if (!(1 <= c.first && c.first <= n && 1 <= c.second && c.second <= m)) {
            continue;
        }
        if (field[c.first][c.second] != 0) {
            if (field[c.first][c.second] == 2) {
                field[c.first][c.second] = 3;
            }
            if (field[c.first][c.second] == 1) {
                cerr << "error" << endl;
            }
            continue;
        } else {
            field[c.first][c.second] = 3;
        }
        q.push(make_pair(c.first + 1, c.second));
        q.push(make_pair(c.first - 1, c.second));
        q.push(make_pair(c.first, c.second + 1));
        q.push(make_pair(c.first, c.second - 1));
        q.push(make_pair(c.first + 1, c.second + 1));
        q.push(make_pair(c.first + 1, c.second - 1));
        q.push(make_pair(c.first - 1, c.second + 1));
        q.push(make_pair(c.first - 1, c.second - 1));
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (field[i][j] == 0 || field[i][j] == 2) {
                return false;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (make_pair(i, j) == free_cell) {
                cout << "c";
                continue;
            }
            cout << (field[i][j] == 1 ? "*" : ".");
        }
        cout << endl;
    }
    return true;
}

void output_1cell(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ((i + j == 0) ? "c" : "*");
        }
        cout << endl;
    }
}

void solveTestCase() {
    cout << endl;
    int n, m, mines;
    cin >> n >> m >> mines;
    int f = n * m - mines;
    int bm_len = 1 << (n * m);
    if (f == 1) {
        output_1cell(n, m);
        return;
    }
    for (int i = 0; i < bm_len; ++i) {
        if (bitCount(i) == mines) {
            if (checkPosition(n, m, i)) {
                return;
            }
        }
    }
    cout << "Impossible" << endl;
}

int main() {
    freopen("input_" PROBLEM ".txt", "rt", stdin); //-V530
    freopen("output.txt", "wt", stdout); //-V530
    int num_tests;
    cin >> num_tests;
    for (int i = 1; i <= num_tests; ++i) {
        cerr << i << "\r" << flush;
        cout << "Case #" << i << ": ";
        solveTestCase();
    }
    return 0;
}