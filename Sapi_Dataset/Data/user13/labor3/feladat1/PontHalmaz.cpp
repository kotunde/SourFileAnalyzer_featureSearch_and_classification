//afgiuh
#include "PontHalmaz.h"
#include "Pont.h"
#include <time.h>
#include<iostream>

PontHalmaz::PontHalmaz(int n) {
	
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		pontok.push_back(Pont(rand(), rand()));
	}
	
	for (int i = 0; i < pontok.size(); ++i) {
		for (int j = i + 1; j < pontok.size(); ++j) {
			tavolsagok.push_back(distance(pontok[i],pontok[j]));
		}
	}
}

double PontHalmaz::maxTavolsag()   const {
	return *max_element(tavolsagok.begin(), tavolsagok.end());
}

double PontHalmaz::minTavolsag() const {
	return *min_element(tavolsagok.begin(), tavolsagok.end());
}

int PontHalmaz:: tavolsagokSzama()  const {
	return tavolsagok.size();
}

int PontHalmaz::kulonbozoTavolsagokSzama()   {
	return unique(tavolsagok.begin(),tavolsagok.end())-tavolsagok.begin();
}

void PontHalmaz::printPontok()     const {
	for (int i = 0; i < pontok.size(); ++i) {
		cout << "( " << pontok[i].getX() << ", " << pontok[i].getY() << ")" << endl;
	}
}

void PontHalmaz::printTavolsagok() const {
	for (int i = 0; i < tavolsagok.size(); ++i) {
		cout << tavolsagok[i] << ", ";
	}
}

void PontHalmaz::rendezPontokX() {
	sort(pontok.begin(), pontok.end(), x_rendez);
}

void PontHalmaz::rendezPontokY() {
	sort(pontok.begin(), pontok.end(), y_rendez);
}

bool x_rendez(const Pont &a, const Pont &b) {
	return a.getX() < b.getX();
}

bool y_rendez(const Pont &a, const Pont &b) {
	return a.getY() < b.getY();
}

void PontHalmaz::rendezTavolsagok() {
	sort(tavolsagok.begin(), tavolsagok.end());
}