#pragma once
#ifndef PROCESSDATA_H
#define PRCOESSDATA_H
#include <iostream>
#include <map>
#include "Student.h"
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

class ProcessData {
	map <int, Student> students;
public:
	ProcessData(string nevek,string roman, string magyar, string matek) {
		ifstream fnevek,fmatek,fmagyar,froman; 
		fnevek.open(nevek); if (!fnevek.is_open()) { cout << "Error at readeing nevek.txt"; system("pause"); }
		fmagyar.open(magyar); if (!fmagyar.is_open()) { cout << "Error at readeing magyar.txt"; system("pause"); }
		froman.open(roman); if (!froman.is_open()) { cout << "Error at readeing roman.txt"; system("pause"); }
		fmatek.open(matek); if (!fmatek.is_open()) { cout << "Error at readeing matek.txt"; system("pause"); }
		
		stringstream ss;
		string line = "";
		while (getline(fnevek, line)) {
			int i=1;
			ss << line << '\n';
			int id;
			string fname, lname;
			ss >> id >> fname >> lname;
			//fname.replace(fname.begin(),fname.end(),'Â','x');
			students.insert(make_pair(i, Student(id, fname, lname)));
			++i;
		}
		cout << ss.str();
		
		
	}
};

#endif