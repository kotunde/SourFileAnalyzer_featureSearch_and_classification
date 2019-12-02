#pragma once
#ifndef SAJATABC_H
#define SAJATABC_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

class SajatAbc {
private:
	static map<char, int> order;
public:
	SajatAbc() {};
	SajatAbc(string filename) {
		ifstream fin;
		fin.open(filename);
		if (!fin) {
			cout << "No file";
			return;
		}
		string line;
		getline(fin,line);
		int l = line.length();
		order.insert(make_pair(' ', 0));
		for (int i = 0; i < l; ++i) {
			
				order.insert(make_pair(line[i], i+1));
			
		}
		/*for (auto &a : order) {
			cout << a.first << " : " << a.second << endl;
		}*/
		fin.close();
	}
	bool operator()(const string& s1, const string& s2) {
		int i = 0;
		int l1 = s1.length();
		int l2 = s2.length();
		while (s1[i] == s2[i] && i < l1 && i < l2) {
			i++;
		}
		if (compchar(s1[i], s2[i])) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool compchar(const char c1, const char c2) {

		if (order[c1] < order[c2]) {
			return true;
		}
		else {
			return false;
		}
	}
};
map<char, int>SajatAbc::order;

#endif /* SAJATABC_H */
