#pragma once
#include "Pont.h"
#include <vector>

bool isSquare(Pont*, Pont*, Pont*, Pont*);
std::vector<Pont*> generatePoints(int);
int * minmaxPoints(std::vector<Pont*>);
void sortPoints(std::vector<Pont*>&);
std::vector<int> tenFarthest(std::vector<Pont*>);