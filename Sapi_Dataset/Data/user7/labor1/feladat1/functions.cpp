#include <iostream>
#include "functions.h"
#include <cmath>

using namespace std;

int CountBits(int number) {
        int result = 0;
        while (number > 0) {
            if ((number % 2) != 0) {
                result += 1;
            }
            number /= 2;
        }
        return result;
}

int setBit(int & n, int order ) {
    n |= (1 << order);
    return order < 32;
}

double mean(double array[], int numElements) {
    int s = 0;
    if (numElements)
    {
        for (int i=0; i< numElements ; ++i){
            s+=array[i];
        }
        return s/numElements;
    }
    return NAN;
}

