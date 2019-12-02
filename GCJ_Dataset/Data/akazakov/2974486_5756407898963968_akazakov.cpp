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

#define PROBLEM "A"

void updatePossibilities(int possibilities []) {
    int answer, x;
    cin >> answer; --answer;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> x; --x;
            if (i == answer) {
                ++possibilities[x];
            }
        }
    }
}

void solveTestCase() {
    int possibilities[16] = { 0 };
    updatePossibilities(possibilities);
    updatePossibilities(possibilities);
    std::vector<int> answers;
    for (int i = 0; i < 16; ++i) {
        if (possibilities[i] == 2) {
            answers.push_back(i);
        }
    }
    switch (answers.size()) {
    case 0:
        cout << "Volunteer cheated!" << endl;
        break;
    case 1:
        cout << answers[0] + 1 << endl;
        break;
    default:
        cout << "Bad magician!" << endl;
        break;
    }
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