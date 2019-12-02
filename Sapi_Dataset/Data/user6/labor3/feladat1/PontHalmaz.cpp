#include "PontHalmaz.h"
#include "Pont.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

struct sortX {
	bool operator() (Pont p1, Pont p2) {
		return p1.getX() < p2.getX();
	}
}sortX1;

struct sortY {
	bool operator() (Pont p1, Pont p2) {
		return p1.getY() < p2.getY();
	}
}sortY1;


void PontHalmaz::tavolsagSzamitas()
{
	for (int i = 0; i < pontok.size()-1 ; ++i) {
		for (int j = i + 1; j < pontok.size(); ++j) {
			double tav = sqrt((pontok[i].getX() - pontok[j].getX())*(pontok[i].getX() - pontok[j].getX()) +
				(pontok[i].getY() - pontok[j].getY())*(pontok[i].getY() - pontok[j].getY()));
			tavolsagok.push_back(tav);
			//cout << endl << "(" << pontok[i].getX() << ", " << pontok[i].getY() << ") "
				//<< "(" << pontok[j].getX() << ", " << pontok[j].getY() << ")" << " tav: " << tav << endl;
		}
	}
}

PontHalmaz::PontHalmaz(int n)
{
	this->n = n;
	srand(time(NULL));
	Pont p;

	for (int i = 0; i < n; ++i) {
		p.setX(rand() % M + 1);
		p.setY(rand() % M + 1);
		if (i == 0) {
			pontok.push_back(p);
			continue;
		}
		for (int j = 0; j < pontok.size(); ++j) {
			if ((pontok[j].getX() == p.getX()) && (pontok[j].getY() == p.getY())) {
				p.setX(rand() % M + 1);
				p.setY(rand() % M + 1);
				j = 0; //ha van ket egyforma pont, akkor ujrageneral egyet s leellenorzi ha benne van mar
			}
		}
		pontok.push_back(p);
	}
	
	tavolsagSzamitas();
}

double PontHalmaz::maxTavolsag() const
{
	return *max_element(tavolsagok.begin(), tavolsagok.end());
}

double PontHalmaz::minTavolsag() const
{
	return *min_element(tavolsagok.begin(),tavolsagok.end());
}

int PontHalmaz::tavolsagokSzama() const
{
	return tavolsagok.size();
}

void PontHalmaz::printPontok() const
{
	for (int i = 0; i < n; ++i) {
		cout << "(" << pontok[i].getX() << ", " << pontok[i].getY() << ")" << endl;
	}
}

void PontHalmaz::printTavolsagok() const
{
	for (int i = 0; i < tavolsagok.size(); ++i) {
		cout << tavolsagok[i] << endl;
	}
}

void PontHalmaz::rendezPontokX()
{
	sort(pontok.begin(), pontok.end(), sortX1);
}

void PontHalmaz::rendezPontokY()
{
	sort(pontok.begin(), pontok.end(), sortY1);
}

void PontHalmaz::rendezTavolsagok()
{
	sort(tavolsagok.begin(), tavolsagok.end());
}

int PontHalmaz::kulonbozoTavolsagokSzama()
{
/*	if (tavolsagok.size() == 1) {
		return 1;
	}
	rendezTavolsagok();
	int s = tavolsagok.size();
	for (int i = 1; i < tavolsagok.size(); ++i) {
		if (tavolsagok[i - 1] == tavolsagok[i]) {
			s = s - 1;
		}
	}
	return s;*/
	rendezTavolsagok();
	vector<double>::iterator it;
	it = unique(tavolsagok.begin(), tavolsagok.end());

	return distance(tavolsagok.begin(), it);
}
