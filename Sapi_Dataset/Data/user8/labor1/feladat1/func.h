#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <cmath>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

//using namespace std;

int countBits(int number);
int setBit(int& number, int order);
double mean(double array[], int numElements);
double * max2(double array[], int numElements);
double stddev(double array[], int numElements);

std::string capitalizeWords(std::string text);
std::string code(std::string text);
std::string decode(std::string text);
int splitText(std::string text);
std::vector<std::string> splitCSVLine(std::string text);


static inline std::string &ltrim(std::string &s);
static inline std::string &rtrim(std::string &s);
static inline std::string &trim(std::string &s);


#endif // FUNC_H_INCLUDED
