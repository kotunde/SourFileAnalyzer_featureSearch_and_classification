#pragma once
#ifndef PONTHALMAZ_H
#define PONTHALMAZ_H
#include "Pont.h"
#include <vector>
#define M 2000

using namespace std;
class PontHalmaz {
	vector<Pont> pontok; 
	int n;
	vector<double> tavolsagok; 

	
	void tavolsagSzamitas();
public:
	PontHalmaz(int n = 100); 

	double maxTavolsag() const; 
	double minTavolsag() const; 

	int tavolsagokSzama() const; 

	void printPontok() const; 
	void printTavolsagok() const; 

	void rendezPontokX(); 
	
	void rendezPontokY(); 
	void rendezTavolsagok(); 

	int kulonbozoTavolsagokSzama(); 
};
#endif /* PONTHALMAZ_H */