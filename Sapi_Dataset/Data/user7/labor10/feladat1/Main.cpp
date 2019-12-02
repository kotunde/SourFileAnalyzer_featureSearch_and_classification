#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Diak.h"
#include "Felveteli.h"
#include <fstream>

using namespace std;

int main() {
	//A- Alpont:
	Felveteli f(2);
	Diak d1("Szabo", "Janos", 6);
	cout << d1;
	Diak d2("Szabo", "Ferenc", 5.25);
	cout << d2;
	Diak d3("Kerekes", "Jozsi", 8.69);
	cout << d3;
	f.beiratkozas(d1);
	f.beiratkozas(d2);
	f.beiratkozas(d3);
	cout << "\n";
	f.kiiratas(cout);
	f.bejutottak(cout);
	
	//B- Alpont:
	ofstream out("ki.txt");
	f.bejutottak(out);
	/*Felveteli f1("be.txt");
	f1.kiiratas(cout);*/
	system("pause");
	return(EXIT_SUCCESS);
}