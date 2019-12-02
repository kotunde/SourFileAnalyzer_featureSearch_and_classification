#pragma once
#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>
#include "Szemely.h"
using namespace std;

class Worker:public Person {
protected:
	string job;

public:
	Worker(string fisrt,string last,int bDate,string job);
	void print(ostream& out);
};

#endif