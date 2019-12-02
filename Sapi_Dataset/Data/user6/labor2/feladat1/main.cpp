#include "Pont.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	//FELADAT 1
	//cout << "4 coordinates, is square or not" << endl;
	ifstream fin;
	fin.open("be.txt");
	if (!fin.is_open()) {
		cout << "No file!" << endl;
	}
	
	Pont a, b, c, d;
	int x, y;
	while (!fin.eof()) {
		fin >> x;
		fin >> y;
		a.setX(x);
		a.setY(y);
		fin >> x;
		fin >> y;
		b.setX(x);
		b.setY(y); fin >> x;
		fin >> y;
		c.setX(x);
		c.setY(y); fin >> x;
		fin >> y;
		d.setX(x);
		d.setY(y);
		cout << "A(" << a.getX() << ", " << a.getY() << ")\tB(" << b.getX() << ", " <<
			b.getY() << ")\tC(" << c.getX() << ", " << c.getY() << ")\tD(" << d.getX() <<
			", " << d.getY() << ")\t Is Square?\t";
		isSquare(a, b, c, d) ? cout << "Yes!" : cout << "No!";
		cout << endl << endl;
	}

	//FELADAT 2/3-rendezes is itt van x,y szerint
	cout << "Random points" << endl;
	vector<Pont> points = generatePoints();
	for (int i = 0; i < N; ++i) {
		cout << points[i].getX() << " " << points[i].getY() << endl;
	}
	cout << endl;
	points = mySort(points);
	for (int i = 0; i < N; ++i) {
		cout << points[i].getX() << " " << points[i].getY() << endl;
	}
	//cout << points[0].getX() << " " << points[0].getY() << endl;
	vector<Pont> mini = minDistance(points);
	vector<Pont> maxi = maxDistance(points);
	cout << "Minimum: " << mini[0].getX() << " " << mini[0].getY() << ", "
		<< mini[1].getX() << " " << mini[1].getY() << endl <<
		"Maximum: " << maxi[0].getX() << " " << maxi[0].getY() << ", "
		<< maxi[1].getX() << " " << maxi[1].getY() << endl << endl;
		

	//FELADAT 4
	cout << "10 legnagyobbtavolsag az origotol:" << endl;
	/*maxi = maxDistanceOrigo(points);
	for (int i = 0; i < 10; ++i) {
		cout << maxi[i].getX() << " " << maxi[i].getY() << endl;
	}
	for (int i = N-1; i > N-200; --i) {
		cout << points[i].getX() << " " << points[i].getY() << endl;
	}*/

	fin.close();
	system("pause");
	return 0;
}