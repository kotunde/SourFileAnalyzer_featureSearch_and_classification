#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>

int countBits(int);
int setBit(int&, int);
double mean(double*, int);
double stddev(double*, int);
double * max2(double*, int);
std::string capitalizeWords(std::string text);
std::string code(std::string text);
int splitText(std::string text);

#endif // FUNCTIONS_H_INCLUDED
