#ifndef FELVETELI_H_INCLUDED
#define FELVETELI_H_INCLUDED

#include <iostream>
#include "Diak.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Felveteli {
protected:
	int helyekSzama;
	vector<Diak> diakok;
public:
	Felveteli(int helyekSzama) : helyekSzama(helyekSzama) {};
	Felveteli(string filenev);
	void beiratkozas(Diak);
	void rendezesABC();
	void rendezesAtlag();
	void kiiratas(ostream& os) const;
	void bejutottak(ostream& os) const;


};
#endif // FELVETELI_H_INCLUDED
