#include <iostream>
#include "functions.h"
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
// trim from start
static inline std::string &ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}
// trim from end
static inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}
// trim from both ends
static inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

int countBits(int number) {
	int mask = 1, count = 0;
	while (mask <= number) {
		if (number & mask) {
			count++;
		}
		mask = mask << 1;
	}
	return count;
}

int setBit(int& number, int order) {
	if (order < 0 || order > 32) {
		return 0;
	}
	number = number | (1 << order);
	return 1;
}

double mean(double array[], int numElements) {
	if (numElements == 0) {
		return NAN;
	}
	double sum = 0;
	for (int i = 0; i < numElements; i++) {
		sum += array[i];
	}
	return sum / numElements;
}

double stddev(double array[], int numElements) {
	if (numElements == 0) {
		return NAN;
	}
	double mn = mean(array, numElements), var = 0;
	for (int i = 0; i < numElements; i++) {
		var += pow(array[i] - mn, 2);
	}
	return sqrt(var);
}

double * max2(double array[], int numElements) {
	double mx[2];
	if (numElements == 0) {
		mx[0] = NAN; mx[1] = NAN;
		return mx;
	}
	mx[0] = array[0]; mx[1] = array[1];
	for (int i = 0; i < numElements; i++) {
		if (mx[0] < array[i]) {
			mx[1] = mx[0]; mx[0] = array[i];
		}
		else {
			if (mx[1] < array[i]) {
				mx[1] = array[i];
			}
		}
	}
	return mx;
}

string capitalizeWords(string text)
{
	text[0] = text[0] - 'a' + 'A';
	for (int i = 1; i < text.length(); i++) {
		if (text[i - 1] == ' ' && text[i] != ' ') {
			text[i] = text[i] - 'a' + 'A';
		}
		else {
			if (text[i] != ' ' && text[i] >= 'A' && text[i] <= 'Z') {
				text[i] = text[i] - 'A' + 'a';
			}
		}
	}
	return text;
}

string code(string text) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'Z') {
			text[i] = 'A';
		}
		else {
			if (text[i] == 'z') {
				text[i] = 'a';
			}
			else {
				if ((text[i] >= 'A' && text[i] < 'Z') || (text[i] >= 'a' && text[i] < 'z')) {
					text[i]++;
				}
			}
		}
	}
	return text;
}

string decode(string text) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'A') {
			text[i] = 'Z';
		}
		else {
			if (text[i] == 'a') {
				text[i] = 'z';
			}
			else {
				if ((text[i] > 'A' && text[i] <= 'Z') || (text[i] > 'a' && text[i] <= 'z')) {
					text[i]--;
				}
			}
		}
	}
	return text;
}


int splitText(string text) {
	int first = 0, last = 0, counter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ' && text[i] != '\t' && text[i] != ',' && text[i] != '!' && text[i] != '?' && text[i] != '.') {
			cout << text[i];
		}
		else {
			cout << endl;
			counter++;
		}
	}
	return counter;
}

vector<string> splitCSVLine(string text) {
	vector<string> csv;
	int commaPosition = text.find(',');
	string word;
	while (commaPosition != string::npos) {
		word = text.substr(0, commaPosition);
		word = trim(word);
		text = text.substr(commaPosition + 1, text.length());
		commaPosition = text.find(',');
		csv.push_back(word);
	}
	csv.push_back(trim(text));
	return csv;
}
