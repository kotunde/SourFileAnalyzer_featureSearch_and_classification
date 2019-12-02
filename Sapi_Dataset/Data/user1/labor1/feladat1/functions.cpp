#include "functions.h"
#include <iostream>
#include <string.h>
#include <cmath>

int countBits (int number){
    int counter = 0;
    while (number){
        ++counter;
        number >>= 1;
    }
    return counter;
}

int setBit (int& number, int order){
    if (order < 0 || order > 31){
        return 0;
    }
    number |= (1UL << order);
    return 1;
}

double mean (double array[], int numElements){
    if (numElements == 0){
        return NAN;
    }
    int counter = 0;
    for (int i = 0; i < numElements; ++i){
        counter += array[i];
    }
    return counter/numElements;
}

double stddev (double array[], int numElements){
    if (numElements == 0){
        return NAN;
    }
    double m = mean(array,numElements);
    double sd = 0;
    for (int i = 0; i < numElements; ++i){
        sd += pow(array[i] - m,2);
    }
    return sqrt(sd/numElements);
}

double* max2 (double array[], int numElements){
    double* a = new double[2];
    double m1 = array[0]; double m2 = array[0];
    for (int i = 0; i < numElements; ++i){
        if (array[i] > m1){
            m2 = m1;
            m1 = array[i];
        }
    }
    a[0] = m1; a[1] = m2;
    return a;
}

string capitalizeWords(string text){
    text[0] = toupper(text[0]);
    for (int i = 0; i < text.length(); ++i){
        if (text[i-1] == ' ') {
            text[i] = toupper(text[i]);
        }
    }
    return text;
}

string code(string text){
    for (int i = 0; i < text.length(); ++i){
        text[i] = char(int(text[i]) + 1);
    }
    return text;
}

string decode(string text){
    for (int i = 0; i < text.length(); ++i){
        text[i] = char(int(text[i]) - 1);
    }
    return text;
}

int splitText(string text){

}
