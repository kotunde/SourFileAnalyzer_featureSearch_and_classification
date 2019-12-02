#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

class Person
{
private:
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

class StringCompare
{
public:
	enum compare_mode { normal, nocase };
	StringCompare(compare_mode cmp = normal) {
		this->cmp = cmp;
	}
	bool operator()(string a, string b) {
		if (cmp == normal) {
			return a < b;
		}
		string A(a);
		string B(b);
		transform(A.begin(), A.end(), A.begin(), ::toupper);
		transform(B.begin(), B.end(), B.begin(), ::toupper);
		return A < B;
		
	}
private:
	compare_mode cmp;
};


class PersonCompare {
public:
	bool operator()(const Person &a, const Person &b) {
		if (a.getFirstName() == b.getFirstName()) {
			return a.getLastName() > b.getLastName();
		}
		return a.getFirstName() > b.getFirstName();
	}
};

int main()
{
	//lambda expression from here
	auto comp = [](string x, string y) { return x > y; };
	set<string,decltype(comp)> s(comp);
	//to here

	typedef set<string, greater<string> > DecreasingStringSet;
	DecreasingStringSet s;
	s.insert("korte");
	s.insert("alma");
	s.insert("eper");
	s.insert("szilva");
	for (auto& x : s) {
		cout << x << " ";
	}
	cout << endl;
	

	typedef set<Person, PersonCompare > Persons;
	Persons a;
	a.insert(Person ("John", "Connor"));
	a.insert(Person("Sarah", "Connor"));
	a.insert(Person("McGregor", "Conor"));
	cout << endl;
	for (auto& x : a) {
		cout << x ;
	}

	set<string, StringCompare> s1;//alapértelmezett mód
	s1.insert("kutya0");
	s1.insert("KUTYA2");

	set<string, StringCompare> s2(StringCompare::nocase);//nocase mód
	s2.insert("kutya0");
	s2.insert("KUTYA2");

	cout << endl << "normal mode:  " ;
	for (auto& x : s1) {
		cout << x << ' ';
	}
	cout << endl << endl << "nocase mode:  " ;
	for (auto& x : s2) {
		cout << x << ' ';
	}
	//string k = "kutya0";
	//string K = "KUTYA2";
	//cout << _stricmp(k.c_str(), K.c_str());
	
	cout << endl << endl;
	system("Pause");
	return 0;
}