#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "Pont.h"
#include <vector>
using namespace std;

bool negyzet_e (Pont,Pont,Pont,Pont);
bool egyenlo (Pont,Pont);
int tavolsag (Pont,Pont);
vector<Pont> legkozelebbi (vector<Pont>,int);
vector<Pont> legkozelebbi_divide(vector<Pont>,int);
vector<Pont> legtavolabbi (vector<Pont>,int);
bool compareX (Pont,Pont);
bool compareY (Pont,Pont);
vector<Pont> legtavolabbi_tiz(vector<Pont>,int);
bool operator== ( const Pont &p1, const Pont &p2);
#endif // FUNCTIONS_H_INCLUDED
