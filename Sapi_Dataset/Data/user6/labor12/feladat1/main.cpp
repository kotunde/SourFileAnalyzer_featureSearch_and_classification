#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>

using namespace std;
int main()
{
	typedef set<string, greater<string> > DecreasingStringSet;
	DecreasingStringSet a;
	a.insert("korte");
	a.insert("alma");
	a.insert("barack");

	for (auto & s : a) {
		cout << s << " " ;
	}

	//lambda expression
	auto comp = [](string x, string y) { return x > y; };
	set<string, decltype(comp)> s(comp);
	s.insert("korte");
	s.insert("alma");
	s.insert("eper");
	s.insert("szilva");
	for (auto& x : s) {
		cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}