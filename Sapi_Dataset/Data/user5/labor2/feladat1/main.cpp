#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"
#include "Pont.h"

#define N 100000

using namespace std;

int main() {
	/*
	Pont * a = new Pont();
	Pont * b = new Pont();
	Pont * c = new Pont();
	Pont * d = new Pont();
	int x, y;
	cin >> x >> y;
	a->setX(x); a->setY(y);
	cin >> x >> y;
	b->setX(x); b->setY(y);
	cin >> x >> y;
	c->setX(x); c->setY(y);
	cin >> x >> y;
	d->setX(x); d->setY(y);

	if (isSquare(a, b, c, d)) {
		cout << "Lehet negyzet." << endl;
	}
	else {
		cout << "Nem lehet negyzet!" << endl;
	}
	*/

	
	vector<Pont*> p = generatePoints(N);
	/*
	int * extremes = minmaxPoints(p);
	cout << "A legtavolabbi pont koordinatai: " << p.at(extremes[0])->getX() << " " << p.at(extremes[0])->getY() << endl;
	cout <<"A legkozelebbi pont koordinatai: " << p.at(extremes[1])->getX() << " " << p.at(extremes[1])->getY() << endl;
	*/

	/*
	sortPoints(p);
	for (int i = 0; i < 1000; i++) {
		cout << p.at(i)->getX() << endl;
	}
	*/

	vector<int> top = tenFarthest(p);
	for (auto& i : top) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}