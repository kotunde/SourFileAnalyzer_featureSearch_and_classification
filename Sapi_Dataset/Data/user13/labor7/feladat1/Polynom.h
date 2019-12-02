#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <algorithm>
using namespace std;
class Polynomial {
		double* coefficients; // Polinom egy�tthat�i
		int capacity; // Polinom egy�tthat�inak a sz�ma
public:
	Polynomial(int degree, const double coefficients[]);
	Polynomial(const Polynomial &that); //Copy Constructor
	Polynomial(Polynomial &&that); //Move Constructor
	~Polynomial(); //Destructor
	
	int degree() const; // Polinom foksz�ma
	
	double evaluate(double x) const; // Polinom �rt�ke a megadott pontban
	
	Polynomial derivative() const; // Polinom deriv�ltja
	double operator[](int index) const;
	friend Polynomial operator-(const Polynomial &a);
	friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
	friend Polynomial operator-(const Polynomial &a, const Polynomial &b);
	friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
	friend ostream & operator <<(ostream& out, const Polynomial& what);
	/*
	copy assignment
	-
	m�ly m�solat letilt�sa �rt�kad�sra n�zve
	*/
	Polynomial & operator = (const Polynomial&) = delete;
	/*
	move assignment
	-
	sek�ly
	m�solat letilt�sa �rt�kad�sra n�zve
	*/
	Polynomial & operator = (Polynomial&&) = delete;
};
#endif