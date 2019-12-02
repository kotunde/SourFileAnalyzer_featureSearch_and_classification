#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <string.h>
#include <vector>
#include <math.h>
#include <regex>

using namespace std;

int countBits(int number)
{
	int db = 0;
	int maszk = 1;
	for (int i = 0; i < 32; i++) {
		if (number&maszk) {
			db++;
		}
		maszk <<= 1;
	}
	return db;
}

int setBit(int& number, int order)
{
	if (order >= 0 and order < 32) {
		int maszk = 1;
		maszk <<= order;
		number = number | maszk;
		return 1;
	}
	return 0;
}

double mean(double array[], int numElements)
{
	double sum = 0;
	for (int i = 0; i < numElements; ++i) {
		sum += array[i];
	}
	return sum /= numElements;
}

double stddev(double array[], int numElements)
{
	if (numElements > 0) {
		double temp2 = 0;
		double temp1 = mean(array, numElements);
		for (int i = 0; i < numElements; ++i) {
			temp2 += pow(array[i] - temp1, 2);
		}
		return sqrt(temp2 / numElements);
	}
	return NAN;
}

double * max2(double array[], int numElements)
{
	double * tomb = new double[2]{ NAN,NAN };
	if (numElements <= 0) {
		return tomb;
	}
	if (numElements == 1) {
		tomb[0] = array[0];
		tomb[1] = array[0];
		return tomb;
	}
	if (array[0] < array[1]) {
		tomb[0] = array[0];
		tomb[1] = array[1];
	}
	else
	{
		tomb[0] = array[1];
		tomb[1] = array[0];
	}
	for (int i = 2; i < numElements; ++i) {
		if (array[i] > tomb[1]) {
			tomb[0] = tomb[1];
			tomb[1] = array[i];
		}
		else {
			if (array[i] > tomb[0]) {
				tomb[0] = array[i];
			}
		}
	}
	return tomb;
}

string capitalizeWords(string text)
{
	text[0] = toupper(text[0]);
	int size = text.length();
	for (int i = 1; i < size; ++i) {
		if (text[i - 1] == ' ') {
			text[i] = toupper(text[i]);
		}
		else {
			text[i] = tolower(text[i]);
		}
	}
	return text;
}

string code(string text)
{
	for (int i = 0; text[i] != '\0'; ++i)
	{
		if (isalpha(text[i])) {
			if (text[i] == 90) {
				text[i] = 65;
				continue;
			}
			if (text[i] == 122) {
				text[i] = 97;
				continue;
			}
			if ((text[i] >= 65 && text[i] < 90) || (text[i] >= 97 && text[i] < 122)) {
				text[i]++;
			}
		}
	}
	return text;
}

string decode(string text)
{
	for (int i = 0; text[i] != '\0'; ++i)
	{
		if (isalpha(text[i])) {

			if (text[i] == 65) {
				text[i] = 90;
				continue;
			}
			if (text[i] == 97) {
				text[i] = 122;
				continue;
			}
			if ((text[i] >= 66 && text[i] <= 90) || (text[i] >= 98 && text[i] <= 122)) {
				text[i]--;
			}
		}
	}
	return text;
}

int splitText(string text)
{
	int db = 0;
	string temp = "";
	for (int i = 0; i < text.length(); ++i) {
		if (text[i] == ' ' || text[i] == '\t' || text[i] == ',' || text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			db++;
			if (text[i] != ' ' || text[i] == '\t' || text[i] == ',' || text[i] == '.' || text[i] == '!' || text[i] == '?') {
				cout << temp << endl;
			}
			temp = "";
			continue;
		}
		temp += text[i];
	}
	if (db == 0) {
		cout << "nincsenek elvalaszto karakterek";
	}
	return db;
}

vector<string> splitCSVLine(string text) {
	vector<string> words;
	text = regex_replace(text, regex("\\s+"), "");
	int prev = 0;
	int currentPos = 0;
	string delimiters = ",";
	string word = "";
	while ((currentPos = text.find_first_of(delimiters, prev)) != string::npos)
	{
		if (currentPos > prev) {
			words.push_back(text.substr(prev, currentPos - prev));
		}
		prev = currentPos + 1;
	}
	if (prev < text.length()) {
		words.push_back(text.substr(prev, string::npos));
	}
	return words;
}