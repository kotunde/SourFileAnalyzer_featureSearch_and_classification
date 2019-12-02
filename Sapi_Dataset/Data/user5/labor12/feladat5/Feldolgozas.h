#pragma once
#include "Diak.h"
#include <map>
#include <utility>

using namespace std;

class Feldolgozas {
	map<int, Diak> Erettsegi;
	string jegyekFiles[3] = {"matek.txt", "magyar.txt", "roman.txt"};
	 jegyek {

	};
public:
	Feldolgozas();
	void readNevek();
	void readJegyek();
	void AVG();
	int countSuccessfull() const;
};