#include <algorithm>
#include "Felveteli.h"
#include <fstream>
#include <cmath>


Felveteli::Felveteli(int helyekszama)
{	
	this->helyekSzama = helyekszama;
}

Felveteli::Felveteli(string file)
{	
	ifstream input; input.open(file); if (!input.is_open()) {throw domain_error("hibas file megnyitas !");}
	
	input >> this->helyekSzama;
	for (;;) {
		
		string fn;
		input >> fn;
		if (input.eof()) {
			break;
		}
		string ln;
		input >> ln;
		double avg;
		input >> avg;

		diakok.push_back(Student(fn, ln, avg));
	}
	input.close();
}

void Felveteli::print(ostream & out)
{
	for (int i = 0; i < diakok.size(); ++i) {
		out << diakok[i];
	}
}

void Felveteli::beiratkozas(Student & diak)
{
	diakok.push_back(diak);
}

void Felveteli::rendezesABC()
{
	sort(diakok.begin(), diakok.end());
}

bool cmpAtlag(Student& a, Student& b) {
	return a.getAverage() > b.getAverage();
}

void Felveteli::rendezesAtlag()
{
	sort(diakok.begin(), diakok.end(), cmpAtlag);
}

void Felveteli::bejutottak(ostream& out)
{
	rendezesAtlag();
	vector<Student>bejutottak;
	for (int i = 0; i < min((size_t)helyekSzama,diakok.size()); ++i) {
		if (diakok[i].getAverage() > 5) {
			bejutottak.push_back(diakok[i]);
		}
	}
	sort(bejutottak.begin(), bejutottak.end());
	for (int i = 0; i < bejutottak.size(); ++i) {
		out << bejutottak[i];
	}
}

void Felveteli::kiirFileba(string file)
{
	ofstream out; out.open(file);
	rendezesAtlag();
	vector<Student>bejutottak;
	for (int i = 0; i < min((size_t)helyekSzama, diakok.size()); ++i) {
		if (diakok[i].getAverage() > 5) {
			bejutottak.push_back(diakok[i]);
		}
	}
	sort(bejutottak.begin(), bejutottak.end());
	for (int i = 0; i < bejutottak.size(); ++i) {
		out << bejutottak[i];
	}
}
