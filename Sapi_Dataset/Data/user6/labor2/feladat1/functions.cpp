#include "functions.h"
#include "Pont.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

struct myclass2 {
	bool operator() (Pont p1, Pont p2) {
		/*if (p1.getX() == p2.getX()) {
			return p1.getY() < p2.getY();
		}
		else if (p1.getX() > p2.getX()) {
			return 0;
		}*/
		return p1.getX() < p2.getX();
	}
}myObject2;

bool isSquare(Pont p1, Pont p2, Pont p3, Pont p4) {
	
	if ((p1.getX() == p3.getX()) || (p2.getX() == p4.getX()) || 
		(p1.getY() == p3.getY()) || (p2.getY() == p4.getY())) {
		return false;
	}
	
	if (distSq(p1, p3) == distSq(p2, p4) && distSq(p1, p2) == distSq(p2, p3)) {
		
		return true;
	}
	else {
		return false;
	}
}

double distSq(Pont a, Pont b) {
	long double sq1 = (a.getX() - b.getX())*(a.getX() - b.getX());
	long double sq2 = (a.getY() - b.getY())*(a.getY() - b.getY());
	return sqrt(sq1+sq2);
}

vector<Pont> generatePoints() {
	srand(time(NULL));
	int i;
	
	vector<Pont> points;
	Pont p;
	for (i = 0; i < N; ++i) {
		p.setX(rand() % 2001);
		p.setY(rand() % 2001);
		points.push_back(p);
	}
	return points;
}

bool myFunction(Pont p1, Pont p2) {
	return p1.getX() > p2.getX(); 
}

vector<Pont> mySort(vector<Pont> points) {
	sort(points.begin(), points.end(), myObject2);
	return points;
}

vector<Pont> minDistance(vector<Pont> points) {
	
	vector<Pont> mini(2);
	for (int k = 0; k < N; k = k + 2) {
		if (points[k].getX() == points[k + 1].getX()) {
			if (points[k].getY() == points[k + 1].getY()) {
				mini[0].setX(points[k].getX());
				mini[0].setX(points[k].getY());
				mini[1].setX(points[k + 1].getX());
				mini[1].setX(points[k + 1].getY());
				break;
			}
		}
	}
	return mini;
}

vector<Pont> maxDistance(vector<Pont> points) {
	
	vector<Pont> maxi(2);
	maxi[0].setX(points[0].getX());
	maxi[0].setY(points[0].getY());
	maxi[1].setX(points[N-1].getX());
	maxi[1].setY(points[N-1].getY());
	return maxi;
}

vector<Pont> maxDistanceOrigo(vector<Pont> points) {
	int i;
	vector<Pont> arrayPoints;
	Pont point;
	Pont origo(0,0);
	double dist = 0, temp;
	


	while (arrayPoints.capacity() <= 10) {
		//cout << "arraypoints capacity: " << arrayPoints.capacity() << endl;
		for (i = N - 1; i > (N / 2); --i) {
			temp = distSq(origo, points[i]);
			//cout << "temp: " << temp << endl;
			if (temp > dist) {
				//cout << "temp: " << temp << endl;
				//cout << "betesz" << endl;
				dist = temp;
				point.setX(points[i].getX());
				point.setY(points[i].getY());
				cout << point.getX() << " " << point.getY() << endl;
				arrayPoints.push_back(point);
			}
		}
		
		//arrayPoints.push_back(point);
	}

	return arrayPoints;
}