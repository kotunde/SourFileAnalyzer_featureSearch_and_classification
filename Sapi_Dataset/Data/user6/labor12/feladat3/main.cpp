#include <iostream>
#include "StringCompare.h"

using namespace std;

int main() {
	typedef set<string, StringCompare> sett;
	sett a;
	a.insert("kicsi");
	a.insert("alma");
	a.insert("korte");
	a.insert("barack");
	a.insert("Lassu");
	a.insert("nagy");
	

	for (auto &s : a) {
		cout << s << endl;
	}

	cout << endl << "**************************************" << endl;
	set<string, StringCompare> sett2(StringCompare::nocase);
	sett2.insert("kicsi");
	sett2.insert("nagy");
	sett2.insert("NagY");
	sett2.insert("ALMA");
	sett2.insert("almacska");
	sett2.insert("barack");
	sett2.insert("Dori");
	for (auto &s : sett2) {
		cout << s << endl;
	}
	system("pause");
	return 0;
}
