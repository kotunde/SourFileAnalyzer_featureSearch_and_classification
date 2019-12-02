#include <cstdlib>
#include "Matrix.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
	Matrix m(4, 4);
	m.fillMatrix(0);
	//Standard kimenetre
	m.printMatrix();
	cout << "********************" << endl;
	m.randomMatrix(1, 10);
	//fajlba iras
	ofstream ofs("matrix.txt");
	if (!ofs) {
		cout << "Fajl megnyitasi hiba" << endl;
		exit(1);
	}
	m.printMatrix(ofs);
	cout << "Negyzetes: " << (m.isSquare() ? "Igen" : "Nem");
	//Milyen konstruktor hivodik? COPY KONSTRUKTOR
	Matrix mm = m;
	mm.printMatrix(ofs);
	cin.get();
	return (EXIT_SUCCESS);
}