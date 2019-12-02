#include <iostream>
#include "Polynom.h"

using namespace std;
int main() {

	double szamok[] = {1,4,7,9};
	double szamok2[] = {1,1,2,3};
	Polynomial poli(3,szamok);
	Polynomial poli2(3, szamok2);
	cout << "poli: " << poli << endl;
	cout << "poli2: " << poli2 << endl;
	cout << "derivaltja: " << poli.derivative() << endl;
	cout << "evaluate: "<< poli.evaluate(1) << endl;
	cout << "2.index: " << poli.operator[](2) << endl;
	cout << "kivonas: " << poli - poli2 << endl;
	cout << "osszeadas: " << poli + poli2 << endl;
	cout << "szorzas: " << poli * poli2 << endl;

	cin.get();
	return 0;
}