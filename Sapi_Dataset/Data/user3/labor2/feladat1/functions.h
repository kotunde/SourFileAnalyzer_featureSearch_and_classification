#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "pont.h"

bool isSquare(Pont p1, Pont p2, Pont p3, Pont p4); //4 pont negyzetet alkot-e
int distanceSquare(Pont p1, Pont p2); //ket pont kozti tavolsag negyzete
void distinctPointsGenerator(Pont P[],int N, int n);
void closestPair_bruteForce(Pont P[],int N);
void farthestPair_bruteForce(Pont P[],int N);
void rendezX(Pont P[], int N);
bool hasonlit(Pont p, Pont q);


#endif // FUNCTIONS_H_INCLUDED
