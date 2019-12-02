#pragma execution_character_set("utf-8")
#include "functions.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
	//proba
	printHello();

	//ISMETLES
	//FELADAT 1
	int i;
	for (i = 0; i < 128; ++i) {
		if (countBits(i) >= 0) {
			cout << i << "-ben 1-es bitek szama: " << countBits(i) << endl;
		}
		else {
			cout << "Problem" << endl;
			return 0;
		}
	}

	cout << endl;

	//FELADAT 2
	int n = 2;
	cout << "Set bit: " << n << " -> ";
	if (!setBit(n,2)) {
		cout << "Problem!!" << endl;
	}
	cout << n << endl;

	cout << endl;

	//FELADAT 3
	cout << "Szamtani kozepe: ";
	int m = 2;
	double *array = new double[m];
	array[0] = 1;
	array[1] = 2.4;
	cout << mean(array, m) << endl;

	cout << endl;

	//FELADAT 4
	cout << "Standard devitation: ";
	m = 20;
	double *array2 = new double[m];
	array2[0] = 9;
	array2[1] = 2;
	array2[2] = 5;
	array2[3] = 4;
	array2[4] = 17;
	array2[5] = 7;
	array2[6] = 8;
	array2[7] = 11;
	array2[8] = 9;
	array2[9] = 3;
	array2[10] = 7;
	array2[11] = 4;
	array2[12] = 12;
	array2[13] = 5;
	array2[14] = 4;
	array2[15] = 10;
	array2[16] = 9;
	array2[17] = 6;
	array2[18] = 9;
	array2[19] = 4;
	cout << stddev(array2, m) << endl;

	cout << endl;

	//FELADAT 5
	cout << "Tomb ket maximuma: ";
	double *maxi = new double[2];
	maxi = max2(array2,m);
	cout << maxi[0] << " " << maxi[1] << endl;

	cout << endl;

	//KARAKTERLANCOK
	//FELADAT 1
	cout << "Capitalize words: " << endl;
	string text;
	getline(cin,text);
	cout << capitalizeWords(text) << endl;

	cout << endl;

	//FELADAT 2
	cout << "Code and decode: " << endl;
	string text2;
	getline(cin, text2);
	text2 = code(text2);
	text2 = decode(text2);

	cout << endl;

	//FELADAT 3
	cout << "Split text into words: " << endl;
	string text3;
	getline(cin, text3);
	cout << splitText(text3) << endl;

	cout << endl;

	//FELADAT 4
	//CSV
    cout << "CSV file" << endl;
	string line = "Alma   ,   Korte   ,    Szilva   ,  Eper";
	cout << line << endl;
	splitCSVLine(line);
	vector<string> items = splitCSVLine(line);
	for (auto& s : items) {
		cout << s << endl;
	}
	
	system("pause");
	return 0;
}