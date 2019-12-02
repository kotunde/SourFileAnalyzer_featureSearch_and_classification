#include <iostream>
#include "Polynomial.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	cout << "-----------------------------------" << endl;
	cout << "Constructor:" << endl;
	cout << "---------------------" << endl;
	double pt1[]{0,3,2};
	Polynomial p1(2, pt1);
	cout << "p1: " << endl << p1 << endl;
	cout << "Copy Constructor:" << endl;
	cout << "---------------------" << endl;
	cout << "Move Constructor:" << endl;
	cout << "---------------------" << endl;
	cout << "Degree:" << p3.degree() << endl;
	cout << "Evaluate:" << p3.evaluate(4) << endl;
}