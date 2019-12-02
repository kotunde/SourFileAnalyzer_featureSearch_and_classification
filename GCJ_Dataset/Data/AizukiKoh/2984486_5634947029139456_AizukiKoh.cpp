#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int compare(string p, string q) {
	int dist = 0;
	for (int i = 0; i < p.length(); ++i) {
		if (p.at(i) == q.at(i)) {
			++dist;
		}
	}
	return dist;
}

bool hasDist(vector<int> list, int dist) {
	vector<int>::iterator it = list.begin();
	while (it != list.end()) {
		if (*it == dist) {
			return true;
		}
		++it;
	}
	return false;
}

/*
void printVector(vector<int> vec){
	vector<int>::iterator it = vec.begin();
	cout << vec.size();
	while(it != vec.end()){
		cout << *it;
		++it;
	}
	cout << endl;
}
*/

int minimumAnswer(vector< vector<int> > dist, int length) {
	int i = 0;
	bool getAnswer = false;
	for (; i <= length; ++i) {
		vector< vector<int> >::iterator it = dist.begin();

		for (int j = 0; j < dist.size(); ++j) {
			//printVector(*it); debug
			getAnswer = true;
			if (!hasDist(*it, i)) {
				getAnswer = false;
				break;
			}
			++it;
		}
		if (getAnswer) {
			return i;
		}
	}
	return -1;
}

int solve(vector<string> p, vector<string> q, int length) {
	vector< vector<int> > dist;
	dist.reserve(p.size()); // p.size() == N

	vector<string>::iterator pit = p.begin();

	for (int i = 0; i < p.size(); ++i) {
		vector<int> temp;
		temp.reserve(p.size());

		vector<string>::iterator qit = q.begin();
		for (int j = 0; j < p.size(); ++j) {
			temp.push_back(compare(*pit, *qit));
			++qit;
		}
		++pit;
		dist.push_back(temp);
	}
	return minimumAnswer(dist, length);
}

void outputAnswer(int x, int y) {
	if (y >= 0) {
		cout << "Case #" << x << ": " << y << "\n";
	} else {
		cout << "Case #" << x << ": NOT POSSIBLE\n";
	}
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	int n;
	int l;

	int ans;

	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> n >> l;
		vector<string> init;
		vector<string> req;
		init.reserve(n);
		req.reserve(n);
		string temp;
		for (int j = 0; j < n; ++j) {
			cin >> temp;
			init.push_back(temp);
		}
		for (int j = 0; j < n; ++j) {
			cin >> temp;
			req.push_back(temp);
		}

		ans = solve(init, req, l);

		outputAnswer(i, ans);
	}
	cout.flush();

	return 0;
}
