#include "Feldolgozas.h"
#include <fstream>
#include <sstream>
#include <string>

Feldolgozas::Feldolgozas(){}

void Feldolgozas::readNevek() {
	ifstream f("nevek1.txt");
	string line;
	int id;
	string vnev, knev;
	while (!f.eof()) {
		f >> id >> vnev >> knev;
		Erettsegi.insert(make_pair(id, Diak(vnev, knev)));
	}
}

void Feldolgozas::readJegyek() {
	ifstream f;
	for (auto& file : jegyekFiles) {
		f.open(file);
		int id;
		double jegy;
		if (file == "matek.txt") {

		}
	}
}