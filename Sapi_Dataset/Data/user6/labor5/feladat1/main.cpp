#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List list1;
	list1.insertFirst(10);
	list1.insertFirst(1);
	list1.insertFirst(180);
	list1.insertFirst(109);
	list1.insertFirst(108);
	list1.insertFirst(106);
	list1.insertFirst(11);
	list1.insertFirst(112);
	cout << list1.size() << endl;
	list1.print();
	list1.remove(112, List::DeleteFlag::GREATER);
	list1.print();
	system("pause");
	return 0;
}