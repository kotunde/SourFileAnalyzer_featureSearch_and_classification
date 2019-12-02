#pragma once
#ifndef  PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;
class Person {
	string mfirstName, mlastName;
public:
	Person(string fname = "", string lname = "") :mfirstName(fname), mlastName(lname) {}
	friend ostream& operator<<(ostream& os, const Person& p) {
		os << p.mfirstName << " " << p.mlastName << endl;
		return os;
	}
	string getFirstName() const { return mfirstName; }
	string getLastName() const { return mlastName; }
	
};
#endif /* PERSON_H */