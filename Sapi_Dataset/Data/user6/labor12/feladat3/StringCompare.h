#pragma once
#ifndef STRINGCOMPARE_H
#define STRINGCOMPARE_H 

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class StringCompare {
public:
	enum compare_mode{normal,nocase};
	StringCompare(compare_mode mode=normal) :mode(mode) {};
	bool operator()(string x, string y) {
		if (this->mode == normal) {
			return x < y;
		}
		if (this->mode == nocase) {
			transform(x.begin(), x.end(), x.begin(), ::tolower);
		    transform(y.begin(), y.end(), y.begin(), ::tolower);
			return x < y;
		}
	}
private:
	compare_mode mode;
};

#endif /* STRINGCOMPARE_H */