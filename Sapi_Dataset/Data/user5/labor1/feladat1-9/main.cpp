#include <iostream>
#include "functions.h"
#include <string>

using namespace std;

int main() {
	double array[] = { 2.45, 1.7, 4.2, 9.356, 4.78 };
	// 1. feladat
	/*for (int i = 0; i < 128; i++) {
		cout << i << ": " << countBits(i) << endl;
	}*/

	// 2. feladat
	/*int number = 0;
	setBit(number, 0);
	setBit(number, 2);
	cout << number << endl;
	*/

	// 3. feladat
	//cout << mean(array, 5) << endl;

	// 4. feladat
	//cout << stddev(array, 5) << endl;

	// 5. feladat
	/*double * h = max2(array, 5);
	cout << h[0] << " " << h[1] << endl;
	*/

	// 6. feladat
	/*string text;
	cout << "Irjon egy szoveget. " << endl;
	getline(cin, text);
	cout << capitalizeWords(text) << endl;
	*/

	// 7. feladat
	/*string text;
	cout << "Irjon egy szoveget. " << endl;
	getline(cin, text);
	cout << code(text) << endl;
	cout << decode(code(text)) << endl;
	*/

	// 8. feladat
	/*string s;
	getline(cin, s);
	splitText(s);
	*/

	// 9. feladat

	string line = "Alma , Korte , Szilva , Eper";
	vector<string> items = splitCSVLine(line);
	for (auto& s : items) {
		cout << s << endl;
	}


	system("pause");
	return 0;
}