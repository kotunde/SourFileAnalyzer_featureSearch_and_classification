#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <string>
using namespace std;

int countBits(int);
int setBit(int&,int);
double mean(double[],int);
double stddev(double[],int);
double* max2(double[],int);

string capitalizeWords(string);
string code(string);
string decode(string);
int splitText(string);

#endif // FUNCTIONS_H_INCLUDED
