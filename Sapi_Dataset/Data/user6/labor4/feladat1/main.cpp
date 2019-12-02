#include <iostream>
#include "Median.h"
#include <exception>
#include <stdexcept>
using namespace std;

int main(int argc, char* argv[]) {
	vector<double> myArray = fillArray(10);
	shuffleArray(myArray);
	printArray(myArray);
	try {
		cout << median(myArray) << endl;
	}
	catch (const exception& e) {
		cout << "No elements" << endl;
	}
	printArray(myArray);





	system("pause");
	return 0;
}