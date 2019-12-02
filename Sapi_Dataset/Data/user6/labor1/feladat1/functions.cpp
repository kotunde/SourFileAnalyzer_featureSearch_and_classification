#pragma warning(suppress : 4996);
#include "functions.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
using namespace std;

void printHello() {
	cout << "Hello" << endl;
}

int countBits(int number) {
	if (number < 0) {
		cout << "Negative introduced number" << endl;
		return -1;
	}
	int s = 0;
	while (number) {
		if (number & 1 == 1) {
			s = s + 1;
		}
		number = number >> 1;
	}
	return s;
}

int setBit(int& number, int order) {
	if ((order < 0) || (order > 31)) {
		return 0;
	}
	number = (1UL << order) + number;
	return 1;
}

double mean(double *array, int numElements) {
	if (!numElements) {
		return NAN;
	}
	double s = 0;
	int i;
	for (i = 0; i < numElements; ++i) {
		s = s + array[i];
	}
	return (s/numElements);
}

double stddev(double *array, int numElements) {
	if (!numElements) {
		return NAN;
	}
	double s1 = 0, s2 = 0;
	int i;
	for (i = 0; i < numElements; ++i) {
		s1 = s1 + array[i];
	}
	s1 = s1 / numElements;
	for (i = 0; i < numElements; ++i) {
		s2 = s2 + ((array[i] - s1)*(array[i] - s1));
	}
	s1 = s2/numElements;
	return sqrt(s1);
}

double * max2(double *array, int numElements) {
	double *maxi = new double[2];
	
	if (!numElements) {
		maxi[0] = maxi[1] = NAN;
		return maxi;
	}

	if (numElements == 1) {
		maxi[0] = maxi[1] = array[0];
		return maxi;
	}

	int i;
	maxi[0] = array[0];
	maxi[1] = array[1];
	for (i = 2; i < numElements; ++i) {
		if (maxi[0] < array[i]) {
			maxi[0] = array[i];
		}
		else {
			if (maxi[1] < array[i]) {
				maxi[1] = array[i];
			}
		}
	}

	if (maxi[0] > maxi[1]) {
		double v = maxi[0];
		maxi[0] = maxi[1];
		maxi[1] = v;
	}
	return maxi;
}

string capitalizeWords(string text)
{
	int l = text.length();
	int i;
	for (i = 0; i < l; ++i) {
		if (i == 0) {
			text[i] = char(int(text[i]) - 32);
			continue;
		}
		if (int(text[i - 1]) == 32) {
			text[i] = char(int(text[i]) - 32);
			continue;
		}
		if (int(text[i]) > 64 && int(text[i]) < 91) {
			text[i] = char(int(text[i]) + 32);
		}
	}
	return text;
}

string code(string text) {
	int l = text.length();
	int i;
	for (i = 0; i < l; ++i) {
		if (int(text[i]) > 64 && int(text[i]) < 90) {
			text[i] = char(int(text[i]) + 1);
			continue;
		}
		if (int(text[i]) == 90) {
			text[i] = 'A';
			continue;
		}
		if (int(text[i]) > 96 && int(text[i]) < 122) {
			text[i] = char(int(text[i]) + 1);
			continue;
		}
		if (int(text[i]) == 122) {
			text[i] = 'a';
			continue;
		}
	}
	cout << text << endl;
	return text;
}

string decode(string text) {
	int l = text.length();
	int i;
	for (i = 0; i < l; ++i) {
		if (int(text[i]) > 65 && int(text[i]) <= 90) {
			text[i] = char(int(text[i]) - 1);
			continue;
		}
		if (int(text[i]) == 65) {
			text[i] = 'Z';
			continue;
		}
		if (int(text[i]) > 97 && int(text[i]) <= 122) {
			text[i] = char(int(text[i]) - 1);
			continue;
		}
		if (int(text[i]) == 97) {
			text[i] = 'z';
			continue;
		}
	}
	cout << text << endl;
	return text;
}

int splitText(string text) {
	int s = 0, i;
	const char *tt = text.c_str();
	
	char const delimiters[] = " ,.?!\t\n";
	char *tok = strtok((char*)tt,delimiters);
	
	while (NULL != tok)
	{
		s = s + 1;
		cout << tok << endl;
		tok = strtok(NULL, delimiters); 
	}
	return s;
}

vector<string> splitCSVLine(string text)
{
	vector<string> items;
	items.clear();
	int index=0;
	string temp;
	while (index != text.find(",")) {
		index = text.find(",");
		temp = text.substr(0, index);
		text.erase(0, index + 1);
		trim(temp);
		items.push_back(temp);
	}
	
	return items;
}

// trim from start
static inline string &ltrim(string &s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(),
		not1(ptr_fun<int, int>(isspace))));
	return s;
}
// trim from end
static inline string &rtrim(string &s) {
	s.erase(find_if(s.rbegin(), s.rend(),
		not1(ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}
// trim from both ends
static inline string &trim(string &s) {
	return ltrim(rtrim(s));
}
