#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	
	string szo;
	cin >> szo;
	vector<char>words(szo.begin(), szo.end());

	sort(words.begin(), words.end());

	cout << string(words.begin(),words.end()) << " " ;

	cout << endl;
	map<string, int>hanyadik;
	do {
		string a(words.begin(), words.end());
		hanyadik.insert(make_pair(a, hanyadik.size()));
	} while (next_permutation(words.begin(), words.end()));

	for (auto a : hanyadik) {
		cout << a.first << '/' << a.second << endl;
	}

	cout << hanyadik["MATEK"] << endl;

	
	system("pause");
	return 0;
}