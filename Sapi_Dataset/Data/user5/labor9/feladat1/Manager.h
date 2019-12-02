#pragma once
#include "Szemely.h"
#include "Alkalmazott.h"
#include <vector>

class Manager : public Alkalmazott {
private:
	vector<Alkalmazott*> beosztottak;
public:
	Manager(string vNev, string kNev, int szEv, string mk) : Alkalmazott(vNev, kNev, szEv, mk){}
	void addAlkalmazott(Alkalmazott*);
	void deleteAlkalmazott(Alkalmazott*);
	int beosztottakSzama() const;
	virtual void print(ostream& os) const;
};