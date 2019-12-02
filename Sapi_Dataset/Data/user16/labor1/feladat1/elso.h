#ifndef ELSO_H_INCLUDED
#define ELSO_H_INCLUDED
#include <string>
#include<vector>

using namespace std;

int countBits(int number);
int setBit(int& number, int order);
double mean(double t[], int numElements);
double stddev(double t[], int numElements);
double * max2(double t[], int numElements);
string capitalizeWords(string text);
string code(string text);
bool isgood(string text);
int splitText(string text);
vector<string> splitCSVLine(string text);



#endif // ELSO_H_INCLUDED
