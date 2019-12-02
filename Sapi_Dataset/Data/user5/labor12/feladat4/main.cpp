#include <iostream>
#include <map>
#include <utility>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	map<string, pair<int, int> > registry;
	fstream f("regiszter1.txt");
	string line;
	string name;
	int birthy, deathy;
	int le = 0;
	while (true) {
		getline(f, line);
		deathy = 0;
		if (!line.empty()) {
			istringstream iss(line);
			iss >> name >> birthy;
			if (iss) {
				iss >> deathy;
			}
			registry.insert(make_pair(name, make_pair(birthy, deathy)));
		}
		else {
			break;
		}
	}
	while (getline(f, line)) {
		istringstream iss(line);
		iss >> name >> deathy;
		auto pos = registry.find(name);
		if (pos != registry.end()) {
			pos->second.second = deathy;
		}
	}
	int dCounter = 0;
	for (auto& x : registry) {
		if (x.second.second != 0) {
			dCounter++;
		}
	}
	cout << dCounter << endl;

	system("pause");
	return 0;
}