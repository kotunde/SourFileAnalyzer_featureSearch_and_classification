#include <iostream>
#include <string>
#include "Person.h"
#include <set>
#include<functional>

using namespace std;

struct PersonCompare {
	bool operator()(const Person&a, const Person&b) {
		if (a.getFirstName().compare(b.getFirstName()) == 0) {
			if (a.getLastName().compare(b.getLastName())<0)
			{
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (a.getFirstName().compare(b.getFirstName()) < 0)
			{
				return true;
			}
			else {
				return false;
			}
		}
	}
};

int main() {

	Person p1("Alma","Zanoska");
	Person p3("Alma","Pistike");
	Person p2("Pi","Gyurika");

	typedef set <Person, PersonCompare> sett;
	sett persons;
	persons.insert(p1);
	persons.insert(p2);
	persons.insert(p3);

	for (auto s : persons) {
		cout << s;
	}

	//lambda expression
	auto comp = [](Person a, Person b) {
		if (a.getFirstName().compare(b.getFirstName()) == 0) {
			if (a.getLastName().compare(b.getLastName()) < 0)
			{
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (a.getFirstName().compare(b.getFirstName()) < 0)
			{
				return true;
			}
			else {
				return false;
			}
		}
	};
	set <Person, decltype(comp)> s(comp);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);

	for (auto k : s) {
		cout << k;
	}

	system("pause");
	return 0;
}