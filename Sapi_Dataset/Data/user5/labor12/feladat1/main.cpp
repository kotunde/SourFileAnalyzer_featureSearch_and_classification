#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>

using namespace std;

int main()
{
	//lambda expression
	auto comp = [](string x, string y) { return x > y; };
	set<string, decltype(comp)> s(comp);
	set < string, greater<string>> s2;
	s2.insert("korte");
	s2.insert("alma");
	s2.insert("eper");
	s2.insert("szilva");
	s.insert("korte");
	s.insert("alma");
	s.insert("eper");
	s.insert("szilva");
	for (auto& x : s) {
		cout << x << " ";
	}
	cout << endl;
	for (auto& x : s2) {
		cout << x << " ";
	}
	system("pause");
	return 0;
}