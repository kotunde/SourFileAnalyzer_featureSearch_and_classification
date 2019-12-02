#pragma once
#ifndef FELVETELI_H
#define FELVETELI_H
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;
class Felveteli
{
	int helyekSzama;
	vector <Student> diakok;
public:
	Felveteli(int helyekszama);
	Felveteli(string file);
	void print(ostream& out = cout);
	void beiratkozas(Student& diak);
	void rendezesABC();
	void rendezesAtlag();
	void bejutottak(ostream& out = cout);
	void kiirFileba(string file);
};

#endif
