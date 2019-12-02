#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>


using namespace std;

typedef set<string, greater<string> > DecreasingStringSet;

int hello()
{
	//lambda expression
	/*auto comp = [](string x, string y) { return x > y; };
	set<string, decltype(comp)> s(comp);*/

	DecreasingStringSet s;
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