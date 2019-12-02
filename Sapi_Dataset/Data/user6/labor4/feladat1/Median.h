#pragma once
#ifndef MEDIAN_H
#define MEDIAN_H
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

vector<double> fillArray(int n);

double median(vector<double>& myArray) throw (domain_error);

void shuffleArray(vector<double>& myArray);

void printArray(vector<double>& myArray);


#endif /* MEDIAN_H */