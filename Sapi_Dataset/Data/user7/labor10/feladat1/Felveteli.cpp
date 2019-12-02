#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Felveteli.h"
#include <fstream>
#include <cmath>

using namespace std;

Felveteli::Felveteli(int num) {
	this->helyekSzama = num;
}
Felveteli::Felveteli(string filename) {
	ifstream fin;
	fin.open(filename);
	if (!fin) {
		throw domain_error("Can't open file!");
	}
	fin >> this->helyekSzama;
	string vnev, knev;
	double atlag;
	fin >> vnev >> knev >> atlag;
	this->diakok.push_back(Diak(vnev, knev, atlag));
	while (!fin.eof()){
		
		fin >> vnev;
		fin >> knev;
		fin >> atlag;
		diakok.push_back(Diak(vnev, knev, atlag));
	}
}


void Felveteli::beiratkozas(Diak d){
	this->diakok.push_back(d);
}

void Felveteli::rendezesABC() {
	sort(diakok.begin(), diakok.end());
}
bool cmp_Atlag(const Diak &d1, const Diak &d2) {
	return d1.getAtlag() > d2.getAtlag();
}
void Felveteli::rendezesAtlag() {
	sort(diakok.begin(), diakok.end(), cmp_Atlag);
}


void Felveteli::kiiratas(ostream& out) {
	out << "Helyek Szama:" << this->helyekSzama << endl;
	out << "Beiratkoztak:\n";
	for (int i = 0; i < this->diakok.size(); ++i) {
		out << "\t" << this->diakok[i] << "\n";
	}
}

void Felveteli::bejutottak(ostream& out) {
	int capacity = min((size_t)this->helyekSzama, diakok.size());
	this->rendezesAtlag();
	out << "Bejutottak: \n";
	for (int i = 0; i < capacity; ++i) {
		if (this->diakok[i].getAtlag() > 5) {
			out << this->diakok[i] << endl;
		}
	}

}