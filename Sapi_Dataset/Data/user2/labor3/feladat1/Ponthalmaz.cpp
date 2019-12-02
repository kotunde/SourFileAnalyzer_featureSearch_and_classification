#include "Pont.h"
#include "Ponthalmaz.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>	

using namespace std;

int koordinatak[2001][2001] { 0 };

PontHalmaz::PontHalmaz(int n) {
	int i = 0;
	while(i<n) {
		Pont temp = Pont(rand() % 2000, rand() % 2000);
			if (!koordinatak[temp.getX()][temp.getY()]) {
				pontok.push_back(temp);
				koordinatak[temp.getX()][temp.getY()] = 1;
				++i;
			}
	}
	tavolsagSzamitas();
}

void PontHalmaz::tavolsagSzamitas() {
	for (int i = 0; i < pontok.size(); ++i) {
		for (int j = i+1; j < pontok.size(); ++j) {
			tavolsagok.push_back(distance(pontok.at(i), pontok.at(j)));
		}
	}
}

double PontHalmaz::maxTavolsag() const {
	return *max_element(tavolsagok.begin(),tavolsagok.end());
}

double PontHalmaz::minTavolsag() const {
	return *min_element(tavolsagok.begin(),tavolsagok.end());
}

int PontHalmaz::tavolsagokSzama() const {
	return tavolsagok.size();
}

void PontHalmaz::printPontok() const {
	for (int i = 0; i < pontok.size(); ++i) {
		cout << i << "(" << pontok.at(i).getX() << " , " << pontok.at(i).getY() << ")" << endl;
	}
}

void PontHalmaz::printTavolsagok() const {
	for (int i = 0; i < tavolsagok.size(); ++i) {
		cout << tavolsagok[i];
	}
}

void PontHalmaz::rendezPontokX() {
	sort(this->pontok.begin(), this->pontok.end(), cmp_x);
}

bool cmp_x(const Pont &a, const Pont &b) {
	return a.getX() < b.getX();
}

void PontHalmaz::rendezPontokY() {
	sort(this->pontok.begin(), this->pontok.end(), cmp_y);
}

bool cmp_y(const Pont &a, const Pont &b) {
	return a.getY() < b.getY();
}

void PontHalmaz::rendezTavolsagok() {
	sort(this->tavolsagok.begin(), this->tavolsagok.end());
}

int PontHalmaz::kulonbozoTavolsagokSzama() {
	rendezTavolsagok();
	return unique(this->tavolsagok.begin(), this->tavolsagok.end()) - this->tavolsagok.begin();
}