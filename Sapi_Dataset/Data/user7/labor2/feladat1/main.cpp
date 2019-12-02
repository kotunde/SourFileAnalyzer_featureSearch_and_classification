#include <cstdlib>
#include <iostream>
#include "Pont.h"
using namespace std;
int main(int argc, char** argv) {
	Pont p1(2, 3);
	cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
	Pont p2(100, 200);
	cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
	Pont * pp1 = new Pont(300, 400);
	Pont * pp2 = new Pont(500, 1000);
	cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
	cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;
	delete pp1;
	delete pp2;
	Pont a(0,10), b(10,0), c(0,0), d(10,10);
	if (negyzet_e(a,b,c,d)) {
		cout << "negyzet";
	}
	else { cout << "negyzetn't"; }
	return (EXIT_SUCCESS);
}
