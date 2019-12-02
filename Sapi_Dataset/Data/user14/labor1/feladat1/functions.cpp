
//
// Created by Tundi on 9/26/2018.
//
#include "functions.h"
#include <cmath>

int countBits(int number)
{
    int nr=0;
    while (number)
    {
        nr+=number&1;
        number=number>>1;
    }
    return nr;
}
int setBit(int& number, int order)
{
    int mask=1;
    if (order>32 || order <0)
    {
        return 0;
    }
    mask=mask<<order;
    number = number | mask;
    return 1;
}
double mean(double array[], int numElements)
{
    int s=0,nr=0,i;
    for (i=0; i<numElements; ++i)
    {
        s=s+array[i];
        nr++;
    }
    if (s==0)
    {
        return NAN;
    }
    else
    {
        return (s/nr);
    }
}
double stddev(double array[], int numElements)
{
    int m=mean(array,numElements);
    int i,s=0;
    for (i=0; i<numElements; ++i)
    {
        s=s+((array[i]-m)*(array[i]-m));
    }
    return sqrt(s/numElements);
}
double * max2(double array[], int numElements)
{
    if (!(numElements))
    {
        double* res;
        res=(double*)malloc(2* sizeof(double));
        res[0]=NAN; res[1]=NAN;
        return res;
    }
    if (numElements==1)
    {
        double* res;
        res=(double*)malloc(2* sizeof(double));
        res[0]=array[0]; res[1]=array[0];
        return res;
    }
    int m1=array[0], m2=array[0],i;
    for (i=2; i<numElements; ++i)
    {
        if (array[i]>m1)
        {
            m2=m1;
            m1=array[i];
        }
        else if (array[i]>m2)
        {
            m2=array[i];
        }
    }
    double* res;
    res=(double*)malloc(2* sizeof(double));
    res[0]=m2; res[1]=m1;
    return res;
}
