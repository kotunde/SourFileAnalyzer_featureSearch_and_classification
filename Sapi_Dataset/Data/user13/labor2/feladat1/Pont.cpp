// Pont.cpp - implementáció
#include "Pont.h"
#include <cmath>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<time.h>
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

double distance(Pont a, Pont b) {						// Ket pont kozotti tavolsag
	int dx = a.getX() - b.getX();
	int dy = a.getY() - b.getY();
	return sqrt((dx * dx) + (dy * dy));
}

int negyzet_e(Pont a, Pont b, Pont c, Pont d) {
	vector <double> szakaszok = {						// Készítsen függvényt, amely ellenőrzi,  
		distance(a, b),									// hogy 4 pont alkothat-e négyzetet.
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

vector <Pont> random_pontok(int n) {	
	srand(time(NULL));											// Véletlenszerűen állítson elő  N=1.000.000 darab pontot 
	vector <Pont> pontok; 								// az [0,2000] x [0,2000] halmazból.
	for (int i = 0; i < n; ++i) {								// A pontokat tárolja egy dinamikus helyfoglalású tömbben.
			pontok.push_back( (rand() % 2001, rand() % 2001));
		}
	return pontok;
}

void rendez_x_szerint(vector <double> pontok) {					// rendezi a fenti alpontban létrehozott pontokat abszcissza (x koordináta)
	sort(pontok.begin(), pontok.end(), x_rendez);			// szerint növekvő sorrendbe majd írassa ki a standard kimenetre
}

bool x_rendez(const Pont &a, const Pont &b) {							  
	return a.getX() < b.getX();
}

vector<Pont> origo_tavolsag(vector <Pont> pontok) {					// meghatározza az origotól legtávolabbi 10 pontot
	Pont origo(0, 0);
	vector <double> tavolsag; 

	for (int i = 0; i < pontok.capacity(); ++i) {
		tavolsag.push_back(distance(origo, pontok[i]));
	}
	sort(tavolsag.begin(), tavolsag.end());
	vector <Pont> tavoliak;
	if (pontok.capacity() < 9) {
		return pontok;
	}
	for (int i = 0; i < pontok.capacity(); ++i) {
		if (distance(origo, pontok[i]) > tavolsag[tavolsag.size() - 9]) {
			tavoliak.push_back(pontok[i]);
		}
	}
	return tavoliak;
}
