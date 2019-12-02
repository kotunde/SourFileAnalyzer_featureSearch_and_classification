#ifndef MEDIAN_cpp
#define MEDIAN_cpp

#include "Median.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


double median(vector<double>& v) throw (domain_error) {
	if (v.empty()) {
		throw domain_error("ures tomb");
	}
	if (v.size() % 2 == 0) {
		nth_element(v.begin(), (v.begin() + v.size() / 2), v.end());
		double x = v[v.size() / 2];
		nth_element(v.begin(), (v.begin() + v.size() / 2 - 1 ), v.end());
		return ((x + v[(v.size() / 2 - 1)]) / 2);
	}
	else{
		nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
		return v[v.size() / 2];
	}
}
#endif // !Median.cpp
