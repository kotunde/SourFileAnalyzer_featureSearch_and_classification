#include "Pont.h"
#include <cmath>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

Pont::Pont(int x, int y) {						//  Konstruktor. ( :: referencia az osztalyra. )
	if (x >= 0 && x <= 2000) this->x = x;
	else
		this->x = 0;
	if (y >= 0 && y <= 2000) this->y = y;
	else
		this->y = 0;
}
int Pont::getX() const {
	return x;
}
int Pont::getY() const {
	return y;
}
void Pont::setX(int x) {
	if (x >= 0 && x <= 2000) this->x = x;
}
void Pont::setY(int y) {
	if (y >= 0 && y <= 2000) this->y = y;
}

void Pont::move(int nx, int ny) {
	if (nx >= 0 && nx <= 2000 && ny >= 0 && ny <= 2000) {
		this->x = nx;
		this->y = ny;
	}
}double distance(Pont a, Pont b) {	int dx = a.getX() - b.getX();	int dy = a.getY() - b.getY();	return sqrt((dx * dx) + (dy * dy));}int negyzet_e(Pont a, Pont b, Pont c, Pont d) {	vector <double> szakaszok = {		distance(a, b),		distance(a, c),		distance(a, d),		distance(b, c),		distance(b, d),		distance(d, c),	};	sort(szakaszok.begin(),szakaszok.end());	for (int i = 0; i < 6; ++i){		cout << szakaszok[i] << " " ;		}	return (szakaszok[0] == szakaszok[3]) && (szakaszok[4] == szakaszok[5]) && (szakaszok[3] < szakaszok[4]);}