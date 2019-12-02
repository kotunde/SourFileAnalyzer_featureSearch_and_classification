#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>

using namespace std;

int countBits(int number);
int setBit(int&, int);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
double* max2(double array[], int numElements);
string capitalizeWords(string text);
string code(string text);
string decode(string text);
int splitText(string text);
vector <string> splitCSVLine(string text);


// trim from start
static inline string &ltrim(string &s);
// trim from end
static inline string &rtrim(string &s);
// trim from both ends
static inline string &trim(string &s);


#endif // FUNCTIONS_H_INCLUDED
