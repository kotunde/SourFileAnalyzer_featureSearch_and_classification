#include "SajatAbc.h"
#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int main() {
	SajatAbc a("be.txt");

	ifstream fin;
	fin.open("bee.txt");
	string line;
	

	set<string, SajatAbc> s1;
	while (getline(fin, line)) {
		s1.insert(line);
	}
	for (auto & a : s1) {
		cout << a << endl;
	}
	fin.close();
	system("pause");
	return 0;
}