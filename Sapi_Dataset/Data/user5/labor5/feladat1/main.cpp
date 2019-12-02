#include "List.h"
#include <iostream>
#include <list>

using namespace std;
bool compare(const List& l1, const list<int>& l2);
void print(const list<int>& l);

int main() {
	List l1;
	list<int> l2;
	l1.insertFirst(2);
	l2.push_front(2);
	l1.print();
	print(l2);
	cout << (compare(l1, l2) ? "Egyenlo" : "Nem Egyenlo") << endl;
	l1.insertFirst(4);
	l2.push_front(4);
	l1.insertFirst(6);
	l2.push_front(6);
	l1.insertFirst(8);
	l2.push_front(8);
	l1.print();
	print(l2);
	cout << (compare(l1, l2) ? "Egyenlo" : "Nem Egyenlo") << endl;
	l1.remove(2, List::DeleteFlag::EQUAL);
	l2.remove(2);
	l1.print();
	print(l2);
	cout << (compare(l1, l2) ? "Egyenlo" : "Nem Egyenlo") << endl;
	l1.remove(6, List::DeleteFlag::LESS);
	l1.print();
	print(l2);
	cout << "6nal nagyobbak torlese:" << endl;
	l1.remove(6, List::DeleteFlag::GREATER);
	l1.print();
	system("pause");
	return 0;
}

bool compare(const List& l1, const list<int>& l2) {
	return l1.size() == l2.size();
}

void print(const list<int>& l) {
	for (auto& le : l) {
		cout << le << " ";
	}
	cout << endl;
}