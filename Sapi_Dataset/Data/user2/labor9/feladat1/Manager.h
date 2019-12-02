#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Alkalmazott.h"

using namespace std;

class Manager : public Alkalmazott {
public:
	Manager(string vezeteknev, string keresztnev, int ev, string munkakor);
	void addAlkalmazott(Alkalmazott*);
	void deleteAlkalmazott(Alkalmazott*);
	int beosztottakSzama();
	void print(ostream&)const;
protected:
	vector<Alkalmazott*> alkalmazottak;
};

#endif // !MANAGER_H
