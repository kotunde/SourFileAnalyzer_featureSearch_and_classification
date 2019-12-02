#pragma once
#ifndef FELVETELI_H
#define FELVETELI_H

#include <iostream>
#include <vector>
#include "Diak.h"

using namespace std;

class Felveteli : public Diak {
private:
	int helyekSzama;
	vector <Diak> diakok;
	struct abcHasonlit {
		bool operator() (Diak &d1, Diak &d2) {
			if (d1<d2) {
				return true;
			}
			else {
				return false;
			}
		}
	} sortABC;

	struct atlagHasonlit {
		bool operator() (Diak &d1, Diak &d2) {
			return d1.getAtlag() > d2.getAtlag();
		}
	} sortAtlag;

public:
	Felveteli(int helyekSzama);
	Felveteli(string fileName);
	void beiratkozas(Diak);
	void rendezesABC();
	void rendezesAtlag();
	void kiiratas(ostream&);
	void bejutottak(ostream&);
};

#endif /* FELVETELI_H */
