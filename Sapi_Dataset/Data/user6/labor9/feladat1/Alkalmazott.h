#pragma once
#ifndef	ALKALMAZOTT_H
#define ALKALMAZOTT_H
#include <iostream>
#include <string>
#include "Szemely.h"

using namespace std;

class Alkalmazott : public Szemely{
protected:
	string munkakor;
	

public:
	Alkalmazott(string, string, int, string);
	virtual void print(ostream&) const;
};


#endif /* ALKALMAZOTT_H */