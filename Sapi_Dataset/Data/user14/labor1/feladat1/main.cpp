#include <iostream>
#include "functions.h"
#include <random>

using namespace std;

int main()
{
    //1.feladat
    int i;
    for (i=0; i<=127; ++i)
    {
        cout << i << "-ben: " << countBits(i)<<endl;
    }

    //2.fel
    int setn =13;
    cout << setBit(setn,1)<<endl << setn << endl;

    //3.fel
    double array[10];
    int n=10;
    for (i=0; i<10; ++i)
    {
        array[i]=(double)(rand()%100);
    }
    cout << mean(array,n)<<endl;

    //4.fel
    cout << stddev(array,n)<<endl;

    //5.fel
    double arr[n];
    for (i=0; i<n; ++i)
    {
        arr[i]=i+1;
    }
    double* a;
    a= max2(arr,n);
    cout <<"5-os fel:  "<< a[0] <<" "<< a[1];


    return 0;
}
