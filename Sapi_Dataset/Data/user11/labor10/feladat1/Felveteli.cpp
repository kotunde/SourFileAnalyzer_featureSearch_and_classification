#include <iostream>
#include "Felveteli.h"
#include "Diak.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
Felveteli::Felveteli( string filenev) {
	ifstream ifs(filenev);
	if (!ifs) {
		cout << "Fajl megnyitasi hiba" << endl;
	}

	ifs >> helyekSzama;

	Diak d;
	while (ifs >> d) {
		cout << d << endl;
		this->beiratkozas(d);

	}

}


void Felveteli::beiratkozas(Diak diak) {
	diakok.push_back(diak);
}

bool compare(Diak& a, Diak& b) {
	if (a.getVnev() == b.getVnev()) {
		return a.getKnev() < b.getKnev();
	}
	return a.getVnev() < b.getVnev();
}

void Felveteli::rendezesABC() {
	sort(diakok.begin(), diakok.end(), compare);
}

struct Atlagok {
	bool operator() (Diak& i, Diak& j) { return (i.getAtlag() < j.getAtlag()); }
} myobject;

void Felveteli::rendezesAtlag() {
	sort(diakok.begin(), diakok.end(), myobject);
}

void Felveteli::kiiratas(ostream& os) const {
	for (auto& diak : diakok) {
		os << diak << endl;
	}
}

void Felveteli::bejutottak(ostream& os) const {
	for (auto& diak : diakok) {
		if (diak.getAtlag() > 5) {
			os << diak << endl;
		}
	}
}

