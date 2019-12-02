#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Board;

 Board readBoard() {
 	Board board;
 	board.resize(4);
	for (int i = 0; i < 4; ++i) {
		board[i].resize(4);
		for (int j = 0; j < 4; ++j) {
			cin >> board[i][j];
		}
	}	
	return board;
}

string solveTest() {
	Board boards[2];
	int rows[2];
	vector<int> rowNumbers[2];

	for (int i = 0; i < 2; ++i) {
		cin >> rows[i];
		--rows[i];
		boards[i] = readBoard();
		rowNumbers[i] = boards[i][rows[i]];
		sort(rowNumbers[i].begin(), rowNumbers[i].end());
	}
	vector<int> intersection;
	set_intersection(rowNumbers[0].begin(), rowNumbers[0].end(), 
					rowNumbers[1].begin(), rowNumbers[1].end(),
					back_inserter<vector<int>>(intersection));

	if (intersection.size() == 0) {
		return "Volunteer cheated!";
	}

	if (intersection.size() == 1) {
		return to_string(intersection.back());
	}

	return "Bad magician!";
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	size_t T;
	scanf("%d\n", &T);
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		string verdict = solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
