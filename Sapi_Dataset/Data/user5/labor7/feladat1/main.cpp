#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
	int num{ 3 };
	double coeff[]{ 4.0, 7.0, 9.0, 2.0 };
	Polynomial p(num, coeff);
	cout << "A p polinom: " <<  p << endl;

	cout << "P foka: " << p.degree() << endl << endl;

	cout << "A p polinom erteke 1ben: " << p.evaluate(1) << endl << endl;

	cout << "A p derivaltja: " << p.derivative() << endl << endl;

	cout << "Negativ P: " << -p << endl << endl;

	double coeff2[]{ 1, -1, 1, -1 };
	Polynomial p2(3, coeff2);
	cout << "A p2 polinom: " << p2 << endl;

	cout << "A ket polinom osszege: " << p + p2 << endl;

	cout << "p - p2 = " << p - p2 << endl;

	cout << "p * p2 = " << p * p2 << endl;

	cout << "p[1] = " << p[1] << endl << endl;
	system("pause");
	return 0;
}