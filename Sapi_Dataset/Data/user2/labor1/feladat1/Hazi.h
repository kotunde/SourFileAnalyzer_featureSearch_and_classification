#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <string>


using namespace std;

int countBits(int number);
int setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
double * max2(double array[], int numElements);
string capitalizeWords(string text);
string code(string text);
string decode(string text);
int splitText(string text);
vector<string> splitCSVLine(string text);