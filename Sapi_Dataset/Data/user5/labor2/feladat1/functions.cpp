#include "functions.h"
#include <iostream>
#include "Pont.h"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

bool compare(Pont* a, Pont* b) {
	return a->getX() < b->getX();
}

double distance(Pont* a, Pont* b) {
	return sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
}

bool isSquare(Pont* a, Pont* b, Pont* c, Pont* d) {
	/*double ab = distance(a, b), ac = distance(a, c), ad = distance(a, d), bc = distance(b, c), bd = distance(b, d), cd = distance(c, d);
	if ((ac == bd && ac != 0 && ab == bc)|| (ad == bc && ad != 0) || (cd == ab && cd != 0) && a != b && b != c && c != d && a != c && a != d && b != d) {
		return true;
	}*/
	vector<double> ds;
	vector<Pont*> pontok;
	pontok.push_back(a); pontok.push_back(b); pontok.push_back(c); pontok.push_back(d);
	double di;
	for (int i = 0; i < pontok.size(); i++) {
		for (int j = i + 1; j < pontok.size(); j++) {
			di = distance(pontok.at(i), pontok.at(j));
			if (di == 0) {
				return false;
			}
			ds.push_back(di);
		}
	}
	double d1, d2; d1 = ds.at(0);
	for (int i = 1; i < ds.size(); i++) {
		if (ds.at(i) != d1) {
			d2 = ds.at(i);
			break;
		}
	}
	int num1 = 0, num2 = 0;
	for (auto& dist : ds) {
		if (dist == d1) {
			num1++;
		}
		else {
			if (dist == d2) {
				num2++;
			}
		}
	}
	if ((num1 == 4 && num2 == 2) || (num1 == 2 && num2 == 4)) {
		return true;
	}
	return false;
}

vector<Pont*> generatePoints(int n) {
	int **t = new int*[2001];
	for (int i = 0; i < 2001; i++) {
		t[i] = new int[2001];
	}
	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			t[i][j] = 0;
		}
	}
	srand(time(0));
	vector<Pont*> p;
	int k = 0, x, y;
	while (k < n) {
		x = rand() % 2001;
		y = rand() % 2001;
		if (t[x][y] == 0) {
			Pont * pont = new Pont(x, y);
			p.push_back(pont);
			k++;
			t[x][y] = 1;
		}
	}

	return p;
}

int * minmaxPoints(vector<Pont*> p) {
	vector<double> distFromOrigo;
	Pont * origo = new Pont();
	for (auto& pont : p) {
		distFromOrigo.push_back(distance(pont, origo));
	}
	int * minmax = new int[2];
	minmax[0] = 0; minmax[1] = 0;
	
	for (int i = 1; i < distFromOrigo.size(); i++) {
		if (distFromOrigo.at(i) > distFromOrigo.at(minmax[0])) {
			minmax[0] = i;
		}
		if (distFromOrigo.at(i) < distFromOrigo.at(minmax[1])) {
			minmax[1] = i;
		}
	}
	return minmax;
}

void sortPoints(vector<Pont*>& p) {
	sort(p.begin(), p.end(), compare);
}

bool compareDistance(double a, double b) {
	return a > b;
}

vector<int> tenFarthest(vector<Pont*> p) {
	vector<int> t;
	vector<double> ds;
	Pont* origo = new Pont();
	for (int i = 0; i < p.size(); i++) {
		ds.push_back(distance(p[i], origo));
	}
	int num = 0, maxi;
	while (num < 10) {
		maxi = 0;
		for (int i = 1; i < ds.size(); i++) {
			if (ds[i] > ds[maxi]) {
				maxi = i;
			}
		}
		t.push_back(maxi);
		ds.erase(ds.begin() + maxi);
		num++;
	}
	return t;
}