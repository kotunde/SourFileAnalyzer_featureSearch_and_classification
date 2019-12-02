#include "Median.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

vector<double> fillArray(int n)
{
	vector<double> myArray;
	for (int i = 0; i < n; ++i) {
		myArray.push_back(i);
	}
	return myArray;
}

double median(vector<double>& myArray) throw(domain_error)
{
	if (myArray.size() == 0) {
		throw exception();
	}
	int n = myArray.size();
	if (n % 2 == 1) {
		nth_element(myArray.begin(), myArray.begin() + (n / 2), myArray.end());
		return myArray[n/2];
	}
	else {
		nth_element(myArray.begin(), myArray.begin() + (n / 2), myArray.end());
		nth_element(myArray.begin(), myArray.begin() + ((n / 2) - 1), myArray.end());
		double med = (myArray[(n / 2) - 1] + myArray[n / 2]) / 2;
		return med;
	}
}

void shuffleArray(vector<double>& myArray) {
	random_shuffle(myArray.begin(),myArray.end());
}

void printArray(vector<double>& myArray) {
	for (auto& e : myArray) {
		cout << e << "\t";
	}
	cout << endl;
}