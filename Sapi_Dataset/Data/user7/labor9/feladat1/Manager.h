#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include "Alkalmazott.h"
#include <vector>

using namespace std;

class Manager:public Alkalmazott {
private:
	vector<Alkalmazott*> beosztottak;
public:
	Manager(string vN, string kN, int szE, string mK);
	void addAlkalmazott(Alkalmazott* alk);
	void deleteAlkalmazott(Alkalmazott* alk);
	int beosztottakSzama() const;
	virtual void print(ostream& out);
};
#endif // !MANAGER_H
