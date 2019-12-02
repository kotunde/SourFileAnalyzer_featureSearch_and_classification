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
	cout << "p1: " << endl << p1 << endl;	cout << "---------------------" << endl;	cout << endl;	cout << "-----------------------------------" << endl;
	cout << "Copy Constructor:" << endl;
	cout << "---------------------" << endl;	Polynomial p2(p1);	cout << "p2: " << endl << p2 << endl;	cout << "---------------------" << endl;	cout << "-----------------------------------" << endl;
	cout << "Move Constructor:" << endl;
	cout << "---------------------" << endl;	Polynomial p3 = std::move(p1);	cout << "p3: " << endl << p3 << endl;	cout << "---------------------" << endl;
	cout << "Degree:" << p3.degree() << endl;
	cout << "Evaluate:" << p3.evaluate(4) << endl;	cout << "Derivate:" << p3.derivative() << endl;	cout << "-----------------------------------" << endl;	cout << "---------------------" << endl;	cout << "Negative: " << -p3 << endl;	cout << "Add: " << (p2+p3) << endl;	cout << "Multiple: " << (p2*p3) << endl; 	cin.get();
}