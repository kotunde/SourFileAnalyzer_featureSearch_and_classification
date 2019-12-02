#include "Polynomial.h"
#include <iostream>

using namespace std;

int main() {
	double c[]{ 7,0,-2,4 };
	Polynomial p1(3,c);
	cout << "p1 polynom degree: " << p1.degree() << endl << endl;
	cout << "p1(x)= " << p1;
	cout << "p1(1)= " << p1.evaluate(-1) << endl << endl;

	Polynomial p2 = p1.derivative();
	cout << "p1'(x)= " << p2;
	cout << "p1'(1)= " << p2.evaluate(-1) << endl << endl;

	cout << "p1(x)+p1'(x)= " << p1 + p2 << endl << endl;

	Polynomial p3 = p2;
	system("pause");
	return 0;
}