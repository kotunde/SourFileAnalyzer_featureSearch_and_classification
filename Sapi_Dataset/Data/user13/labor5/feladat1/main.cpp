#include<iostream>
#include "List.h"

using namespace std;



int main() {
	List x;
	
	x.insertFirst(1);
	x.insertFirst(2);
	x.insertFirst(3);
	x.insertFirst(4);
	x.insertFirst(5);
	x.insertFirst(8);
	x.exists(4) ? cout << "van" : cout << "nincs";
	cout << endl;
	x.exists(7) ? cout << "van" : cout << "nincs";
	cout << endl;
	cout << "size: " << x.size();
	cout << endl;
	x.insertFirst(69);
	cout << "size: " << x.size();


	cout << endl;
	x.print();
	cout << endl;
	cout << " Mit akarsz kitorolni? ";
	int ficsor;
	cin >> ficsor;
	cout << "fiiiicsor: ";
	x.remove(ficsor, List::DeleteFlag::Ficsor);
	x.print();
	cout << "HAHAHAHA"; 
	x.remove(4, List::DeleteFlag::GREATER);
	x.remove(4, List::DeleteFlag::LESS);

	
	
	
	cout << endl;
	x.print();
	cin.get();
	return EXIT_SUCCESS;
}

