#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void conv(string s, vector<vector<int*> > &dataset) {
	char now;
	vector<int*> ans;
	for (int i = 0; i < s.length(); ++i) {
		if (i == 0) {
			now = s.at(0);
			int *temp = new int[2];
			temp[0] = now;
			temp[1] = 1;
			ans.push_back(temp);
		} else if (s.at(i) == now) {
			++ans.at(ans.size()-1)[1];
		} else {
			now = s.at(i);
			int *temp = new int[2];
			temp[0] = now;
			temp[1] = 1;
			ans.push_back(temp);
		}
	}
	dataset.push_back(ans);
}

void convert(vector<string> input, vector<vector<int*> > &dataset) {
	vector<string>::iterator it = input.begin();
	while (it != input.end()) {
		conv(*it, dataset);
		++it;
	}
}

int solve(vector<string> input) {
	vector<vector<int*> > dataset;
	convert(input, dataset);
	bool canAns = true;
	for (int i = 1; i < dataset.size(); ++i) {
		if (dataset.at(0).size() != dataset.at(i).size()) {
			return -1;
		}
	}
	for (int i = 1; i < dataset.size(); ++i) {
		for (int j = 0; j < dataset.at(0).size(); ++j) {
			if (dataset.at(0).at(j)[0] != dataset.at(i).at(j)[0]) {
				canAns = false;
				break;
			}
		}
		if (!canAns) {
			break;
		}
	}
	if (!canAns) {
		return -1;
	}
	int min;
	int max;
	int ans = 0;
	for (int j = 0; j < dataset.at(0).size(); ++j) {
		min = 100;
		max = 0;
		for (int i = 0; i < dataset.size(); ++i) {
			if (dataset.at(i).at(j)[1] > max) {
				max = dataset.at(i).at(j)[1];
			}
			if (dataset.at(i).at(j)[1] < min) {
				min = dataset.at(i).at(j)[1];
			}
		}
		ans += max - min;
	}
	return ans;
}

void printAnswer(int x, int ans) {
	if (ans == -1) {
		cout << "Case #" << x << ": Fegla Won\n";
	} else {
		cout << "Case #" << x << ": " << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	int N;
	int ans = 0;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		vector<string> input;
		cin >> N;
		string temp;
		for (int j = 0; j < N; ++j) {
			cin >> temp;
			input.push_back(temp);
		}
		ans = solve(input);
		printAnswer(i + 1, ans);
	}
	cout.flush();
	return 0;
}
