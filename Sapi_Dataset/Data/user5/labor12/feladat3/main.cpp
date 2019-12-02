#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class StringCompare {
	int mode;
public:
	enum compare_mode { normal, nocase };
	StringCompare(int mode = StringCompare::normal): mode(mode) {}
	bool operator()(const string& s1, const string& s2) {
		if (this->mode == StringCompare::normal) {
			return s1 < s2;
		}
		else {
			string ss1 = s1, ss2 = s2;
			transform(ss1.begin(), ss1.end(), ss1.begin(), tolower);
			transform(ss2.begin(), ss2.end(), ss2.begin(), tolower);
			return ss1 < ss2;
		}
	}
};

int main() {
	set<string, StringCompare> s(StringCompare::nocase);
	s.insert("Istvan"); s.insert("laptop"); s.insert("Korte"); s.insert("alma");
	for (auto& x : s) {
		cout << x << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}