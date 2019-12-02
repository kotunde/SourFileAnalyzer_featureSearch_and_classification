#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define N 100
#include "Pont.h"
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <float.h>
#include <map>
using namespace std;


double distance(const Pont& p1, const Pont& p2);
bool isSquare (const Pont& a, const Pont& b, const Pont&c, const Pont& d);
void generate_set();
void print(vector<Pont> pontok);
void sortByX(vector<Pont> pontok);
void furthestOrigin(vector<Pont> pontok);
void minMaxDistance(vector<Pont> pontok);
void initiate();

struct EntityComp {
  int property;
  EntityComp(int property) {this->property = property;}
  bool operator()(const Pont& s1, const Pont& s2) const {
      if(property == 1){return s1.getX() < s2.getX();}
      if(property == 2){return s1.getY() < s2.getY();}

  }
};

float closest(Pont P[], int n);

#endif // FUNCTIONS_H_INCLUDED
