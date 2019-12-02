#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int deceit(vector<double> naomi, vector<double> ken) {
	int n = naomi.size();
	int win = 0;
	for (int i = 0; i < n; ++i) {
		while (naomi.back() > ken.back()) {
			++win;
			++i;
			naomi.pop_back();
			ken.pop_back();
			if (naomi.size() == 0) {
				return win;
			}
		}
		naomi.erase(naomi.begin());
		ken.pop_back();
	}
	return win;
}

int optimal(vector<double> &naomi, vector<double> &ken) {
	int n = naomi.size();
	bool flag;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < ken.size(); ++j) {
			flag = true;
			if (naomi.front() < ken[j]) {
				naomi.erase(naomi.begin());
				ken.erase(ken.begin() + j);
				flag = false;
				break;
			}
		}
		if (flag) {
			return naomi.size();
		}
	}
	return naomi.size();
}

void outputAnswer(int x, int y, int z) {
	cout << "Case #" << x << ": " << y << " " << z << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	int n;
	int y;
	int z;
	double temp;

	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> n;
		vector<double> naomi;
		vector<double> ken;
		naomi.reserve(n);
		ken.reserve(n);
		for (int j = 0; j < n; ++j) {
			cin >> temp;
			naomi.push_back(temp);
		}
		for (int j = 0; j < n; ++j) {
			cin >> temp;
			ken.push_back(temp);
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		y = deceit(naomi, ken);
		z = optimal(naomi, ken);
		outputAnswer(i, y, z);
	}
	cout.flush();
	return 0;
}
