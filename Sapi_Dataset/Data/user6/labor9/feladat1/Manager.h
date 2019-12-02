#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include "Alkalmazott.h"

using namespace std;

class Manager:public Alkalmazott {
protected:
	vector<Alkalmazott*> beosztottak;

public:
	Manager(string, string, int, string);
	void addAlkalmazott(Alkalmazott*);
	void deleteAlkalmazott(Alkalmazott*);
	int beosztottakSzama();
	virtual void print(ostream&) const;
};

#endif /* MANAGER_H */
