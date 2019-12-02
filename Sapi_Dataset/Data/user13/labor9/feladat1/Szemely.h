#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:			// a protectedet #-el jeloltuk pdf-ben	, minusszal (-) privat, plusszal (+) public
	string firstName;
	string lastName;
	int birthDate;
public: 
	Person(string, string, int);
	void print(ostream&);
};

#endif