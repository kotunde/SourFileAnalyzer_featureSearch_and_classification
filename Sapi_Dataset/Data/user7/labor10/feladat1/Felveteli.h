#pragma once

#ifndef FELVETELI_H
#define FELVETELI_H

#include <vector>
#include "Diak.h"

using namespace std;

class Felveteli {
private:
	int helyekSzama;
	vector<Diak> diakok;
public:
	Felveteli(int);
	Felveteli(string filename);
	void beiratkozas(Diak);
	void rendezesABC();
	void rendezesAtlag();
	void kiiratas(ostream& out);
	void bejutottak(ostream& out);
};
#endif // !FELVETELI_H
