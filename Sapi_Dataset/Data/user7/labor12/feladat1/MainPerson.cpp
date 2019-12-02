#include <iostream>
#include <string>
#include <functional>
#include <set>
#include "Person.h"

using namespace std;

//class PersonCompare {
//public:
//	bool operator()(const Person& p1, const Person& p2) {
//		if (p1.getLastName() == p2.getLastName()) {
//			return p1.getFirstName() < p2.getFirstName();
//		}
//		else {
//			return p1.getLastName() < p2.getLastName();
//		}
//	}
//};

//typedef set<Person, PersonCompare> PCompare;

//Fuggvenyobjektum:
class StringCompare {
public:
	enum compare_mode { normal, nocase };
	StringCompare(compare_mode cmp = normal) { this->compare = cmp; }
	bool operator()(string x, string y) {
		if (compare = normal) {
			return x < y;
		}
		else {
			string sp1 = x;
			string sp2 = y;
			for (auto& a : sp1) { a = tolower(a); }
			for (auto& b : sp1) { b = tolower(b); }
			return sp1 < sp2;

		}
	}
private:
	compare_mode compare;
	
};

set<string, StringCompare> s1;//alapértelmezett mód
set<string, StringCompare> s2(StringCompare::nocase);//nocase mód

int main() {
	//lambda expression
	auto comp = [](const Person& p1, const Person& p2) {
		if (p1.getLastName() == p2.getLastName()) {
		return p1.getFirstName() < p2.getFirstName();
		}
		else {
			return p1.getLastName() < p2.getLastName();
		} 
	};
	set<Person, decltype(comp) > p(comp);
	//PCompare p;
	p.insert(Person ("korte","jozsi"));
	p.insert(Person("alma","feri"));
	p.insert(Person("eper","bali"));
	p.insert(Person("szilva","pistike"));
	for ( auto& x : p) {
		cout << x << " ";
	}
	cin.get();
	return 0;
}