#pragma once
#ifndef DIAK_H
#define DIAK_H
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string firstName;
	string lastName;
	double average;
public:
	Student(string fname, string lname, double avg);
	double getAverage() const;
	string getFristName() const;
	string getLastName() const;
	
	friend ostream& operator<<(ostream& out,const Student&);
	friend istream& operator>>(istream& in, Student&);

};

bool operator<(const Student& a, const Student& b);

#endif