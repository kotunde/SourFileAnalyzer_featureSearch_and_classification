#include <iostream>
#include <algorithm>
#include <set>
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

class PersonCompare {
public:
	bool operator()(const Person& p1, const Person& p2) {
		if (p1.getLastName() == p2.getLastName()) {
			return p1.getFirstName() < p2.getFirstName();
		}
		else {
			return p1.getLastName() < p2.getLastName();
		}
	}
};

int main() {
	auto compare = [](const Person& p1, const Person& p2) { if (p1.getLastName() == p2.getLastName()) return p1.getFirstName() < p2.getFirstName(); else return p1.getLastName() < p2.getLastName(); };
	set<Person, decltype(compare)> p;
	p.insert(Person("Janos", "Szabo"));
	p.insert(Person("Istvan", "Fekete"));
	p.insert(Person("Lajos", "Kovacs"));
	p.insert(Person("Bela", "Szabo"));
	for (auto& person : p) {
		cout << person;
	}
	system("pause");
	return 0;
}