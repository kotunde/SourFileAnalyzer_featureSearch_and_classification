// Pont.cpp - implementáció
#include "Pont.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>

using namespace std;

Pont::Pont(int x, int y) {						//  a ket kettospont jelzi hogy a Pont konstruktor milyen osztalyhoz tartozik 
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
}  

double distance(Pont a, Pont b) {
	int dx = a.getX() - b.getX();
	int dy = a.getY() - b.getY();
	return sqrt((dx * dx) + (dy * dy));
}

int negyzet_e(Pont a, Pont b, Pont c, Pont d) {
	vector <double> szakaszok = {
		distance(a, b),
		distance(a, c),
		distance(a, d),
		distance(b, c),
		distance(b, d),
		distance(d, c),
	};
	sort(szakaszok.begin(),szakaszok.end());
	for (int i = 0; i < 6; ++i){
		cout << szakaszok[i] << " " ;
		}
	return (szakaszok[0] == szakaszok[3]) && (szakaszok[4] == szakaszok[5]) && (szakaszok[3] < szakaszok[4]);

}

Pont* p_gen(int n) {
	//vector <Pont> points(n, 0);
	Pont *points = new Pont[n];
	for (int i = 0; i < n; i++) {
		points[i].setX(rand() % 2001);
		points[i].setY(rand() % 2001);
	}
	return points;
}

//void sortX(Pont* points) {
//	sort(points->getX.begin(), points->getX.end());
//}
//
//double d_origo(Pont* points) {
//	Pont origo(0, 0);
//	vector <double> dist(10, 0);
//	for (int i = 0; i < sizeof(points); ++i) {
//		dist[i] = distance(origo, points[i]);
//	}
//	sort(dist.end(), dist.begin());
//	for (int i = 0; i < 10; ++i) {
//		return dist[i];
//	}
//}


