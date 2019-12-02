#include "functions.h"
#include <cmath>

int countBit (int number){
    int result = 0;
        while (number > 0) {
            if ((number % 2) != 0) {
                result += 1;
            }
            number /= 2;
        }
        return result;
}

int setBit (int &number,int order){
    number |= (1 << order);
    return order < 32;
}

double mean (double array[], int numElements){
    double sum = 0;
    if(numElements){
        for (int i = 0; i < numElements; ++i) {
            sum += array[i];
        }
        return sum / numElements;
    }
     else return NAN;
}
double stddev(double array[], int numElements){
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i = 0; i < 10; ++i)
    {
        sum += array[i];
    }

    mean = sum/10;

    for(i = 0; i < 10; ++i)
        standardDeviation += pow(array[i] - mean, 2);

    return sqrt(standardDeviation / 10);
}
