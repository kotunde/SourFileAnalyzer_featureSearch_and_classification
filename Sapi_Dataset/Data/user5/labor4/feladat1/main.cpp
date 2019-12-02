#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

double median(vector<double>&);
void print(const vector<double>&);

int main() {
	//vector<double> t{ 1, 2, 5, 4, 3, 1, 4, 3, 3, 4, 3, 5, 1 };
	vector<double> t{ 1, 4, 2, 4, 2, 3, 5, 3, 1, 1 };
	random_shuffle(t.begin(), t.end());
	cout << "Veletlenszeru keveres utan: " << endl;
	print(t);
	try {
		cout << "A median: " << median(t) << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}

void print(const vector<double>& t) {
	for (auto& el : t) {
		cout << el << " ";
	}
	cout << endl;
}

double median(vector<double>& t) {
	if (t.empty()) {
		throw domain_error("A tomb ures!");
	}
	else {
		if (t.size() % 2) {
			cout << "Paratlan szamu: " << endl;
			nth_element(t.begin(), t.begin() + (t.size() / 2), t.end());
			print(t);
			return t.at((t.size() / 2));
		}
		else {
			cout << "Paros szamu: " << endl;
			double sum = 0;
			nth_element(t.begin(), t.begin() + (t.size() / 2 - 1), t.end());
			sum += t.at((t.size() / 2 - 1));
			print(t);
			nth_element(t.begin(), t.begin() + (t.size() / 2), t.end());
			sum += t[(t.size() / 2)];
			print(t);
			return sum / 2;
		}
	}
}