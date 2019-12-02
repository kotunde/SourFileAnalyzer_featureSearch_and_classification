#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "Szemely.h"
#include "Worker.h"
#include <vector>
using namespace std;

class Manager :public Worker{
private: 
	vector <Worker*> subaltern;
public:
	Manager(string fisrt,string last, int bDate, string job);
	void addSubaltern(Worker* who);
	void deleteSubaltern(Worker* who);
	int nrOfSubalterns() const;
	void print(ostream& out);

};

#endif