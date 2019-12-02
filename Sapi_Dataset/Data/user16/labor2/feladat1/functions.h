#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "Pont.h"
#include <vector>

using namespace std;

bool negyzet (const Pont * a);
double dist (const Pont &a, const Pont &b);
vector <Pont> felvesz (int);
void rendez (vector<Pont> );
void rendez2 (vector<Pont> );
bool myfunction (const Pont &, const Pont &);
bool myfunction2 (const Pont &, const Pont &);
void kiir (vector<Pont>);
int compare (const void  *, const void *);
int compare2 (const void  *, const void *);
void legtavolabbiak (vector<Pont>);
void legk(vector<Pont>);


#endif // FUNCTIONS_H_INCLUDED
