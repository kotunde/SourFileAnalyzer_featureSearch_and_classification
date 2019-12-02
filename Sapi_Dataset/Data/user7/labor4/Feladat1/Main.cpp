#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdexcpt.h>
#include <time.h>

using namespace std;

double median(vector<double> &);
int main() {
	srand(time(0));
	vector<double> numbers;
	for (int i = 0; i < 10 ; ++i) {
		numbers.push_back(rand()%100);
	}
	for (double d : numbers) {
		cout << d << " ";
	}
	cout << endl;
	/*for (int i = 0; i < numbers.size(); ++i) {
		cout << numbers.at(i) << " , ";
	}*/
	median(numbers);
	cin.get();
	return 0;
}
double median(vector<double> &numbers) throw (domain_error) {
	if (!numbers.size()) {
		throw domain_error("Empty vector.");
	}
	nth_element(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.end());
	for (double d : numbers) {
		cout << d << " ";
	}
	cout << endl;
	if (numbers.size() % 2 == 0) {
		nth_element(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.end());
		double median = ( numbers[numbers.size()/2] + numbers[(numbers.size()/2) -1] ) / 2;
		cout << "The median is :" << median << '\n';
	}
	if  (numbers.size() % 2 == 1) {
		double median = numbers[numbers.size() / 2];
		cout << "The median is :" << median << '\n';
	}
}
