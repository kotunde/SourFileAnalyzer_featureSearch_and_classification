#pragma once
#ifndef _FUNC_H
#define _FUNC_H

#define N 10
#include "Pont.h"
#include <vector>

bool isSquare(Pont, Pont, Pont, Pont);
double distSq(Pont, Pont);
vector<Pont> generatePoints();
vector<Pont> mySort(vector<Pont> points);
bool myFunction(Pont p1, Pont p2);
vector<Pont> maxDistance(vector<Pont> points);
vector<Pont> minDistance(vector<Pont> points);
vector<Pont> maxDistanceOrigo(vector<Pont> points);

#endif