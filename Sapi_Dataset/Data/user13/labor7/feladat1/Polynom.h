#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <algorithm>
using namespace std;
class Polynomial {
		double* coefficients; // Polinom együtthatói
		int capacity; // Polinom együtthatóinak a száma
public:
	Polynomial(int degree, const double coefficients[]);
	Polynomial(const Polynomial &that); //Copy Constructor
	Polynomial(Polynomial &&that); //Move Constructor
	~Polynomial(); //Destructor
	
	int degree() const; // Polinom fokszáma
	
	double evaluate(double x) const; // Polinom értéke a megadott pontban
	
	Polynomial derivative() const; // Polinom deriváltja
	double operator[](int index) const;
	friend Polynomial operator-(const Polynomial &a);
	friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
	friend Polynomial operator-(const Polynomial &a, const Polynomial &b);
	friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
	friend ostream & operator <<(ostream& out, const Polynomial& what);
	/*
	copy assignment
	-
	mély másolat letiltása értékadásra nézve
	*/
	Polynomial & operator = (const Polynomial&) = delete;
	/*
	move assignment
	-
	sekély
	másolat letiltása értékadásra nézve
	*/
	Polynomial & operator = (Polynomial&&) = delete;
};
#endif