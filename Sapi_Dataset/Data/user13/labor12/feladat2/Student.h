#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
private:
	int id;
	string firstName;
	string lastName;
	float magyar;
	float matek;
	float roman;

public:
	Student(int id, string fname, string lname) {
		this->id = id;
		this->firstName = fname;
		this->lastName = lname;
	}
	string GetFname() {
		return firstName;
	}
	string getLname() {
		return lastName;
	}

	void setMagyar(float jegy) {
		this->magyar = jegy;
	}
	void setMatek(float jegy) {
		this->matek = jegy;
	}
	void setRoman(float jegy) {
		this->roman = jegy;
	}

	bool pass() {
		return matek >= 5 && magyar >= 5 && roman >= 5 && average() >= 6;
	}

	float average() {
		return (matek + magyar + roman) / 3;
	}
	
};

#endif