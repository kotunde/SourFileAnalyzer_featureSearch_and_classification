#include <iostream>
#include "Diak.h"
#include "Felveteli.h"
#include <string>
#include <fstream>

using namespace std;

int main() {

	Diak d1("Kis", "Pistike", 9.7);
	Diak d2("Nagy", "Mariska", 8.56);

	if (d1 < d2) {
		cout << d1 << d2 << endl;
	}
	else {
		cout << d2 << d1 << endl;
	}

	Diak d3("Pista", "Gyurika", 7.56);
	Diak d4("Nagy", "Andrea", 3.4);

	Felveteli f1(2);
	f1.beiratkozas(d1);
	f1.beiratkozas(d2);
	f1.beiratkozas(d3);
	f1.beiratkozas(d4);

	cout << "ABC szerint rendezve:" << endl;
	f1.rendezesABC();
	f1.kiiratas(cout);

	f1.bejutottak(cout);

	Felveteli f2("be.txt");
	//f2.kiiratas(cout);

	ofstream fout;
	fout.open("bejutottak.txt");
	f2.bejutottak(fout);

	system("pause");
	return 0;
}