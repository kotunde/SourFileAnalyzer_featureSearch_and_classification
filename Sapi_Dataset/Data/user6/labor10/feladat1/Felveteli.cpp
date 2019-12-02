#include "Felveteli.h"
#include <algorithm>
#include <fstream>

Felveteli::Felveteli(int helyekSzama)
{
	this->helyekSzama = helyekSzama;
}

Felveteli::Felveteli(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	if (!fin) {
		cout << "No file";
		return;
	}


	fin >> this->helyekSzama;
	Diak d("","",0);
	while (fin >> d) {
		diakok.push_back(d);
	}

	/*while (!fin.eof()) {
		string vnev, knev;
		double atlag;
		fin >> vnev >> knev;
		fin >> atlag;
		Diak d(vnev,knev,atlag);
		diakok.push_back(d);
	}*/

	fin.close();
}

void Felveteli::beiratkozas(Diak d)
{
	diakok.push_back(d);
}

void Felveteli::rendezesABC()
{
	sort(diakok.begin(), diakok.end(), sortABC);
}

void Felveteli::rendezesAtlag()
{
	sort(diakok.begin(), diakok.end(), sortAtlag);
}

void Felveteli::kiiratas(ostream &os)
{
	for (int i = 0; i < diakok.size(); ++i) {
		os << diakok[i];
	}
	os << endl;
}

void Felveteli::bejutottak(ostream &os)
{
	os << "Bejutottak:" << endl;
	vector <Diak> temp = diakok;
	sort(temp.begin(), temp.end(), sortAtlag);
	for (int i = 0; i < helyekSzama; ++i) {
		if (temp[i].getAtlag() >= 5) {
			os << temp[i];
		}
	}
	os << endl;
}


