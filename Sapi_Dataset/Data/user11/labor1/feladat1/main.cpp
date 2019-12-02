#include <iostream>
#include "lab1.h"
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int i;
   //1
    for(i=0;i<=127;++i){
        cout<<"az "<<i<<"-dik pozicioban levo elem 1 bitjenek szama:"<<countBits(i)<<endl;
    }
    //2
    int szam;
    szam=1;
    setBit(szam,2);
    cout<<countBits(szam)<<endl;
    //3
     double a[]={1,2,9};
    cout<<"atlag "<<mean(a,3)<<endl;
    //4
    cout<<"szoras "<<stddev(a,3)<<endl;
   //5
   double *maxi=new double[2];
   maxi=max2(a,3);
    cout<<"max "<<maxi[0]<< " ,"<<maxi[1]<<endl;
   //5 a string
    string text1="Sut a nap",text2;
    cout<<"a mondat "<<text1<<endl;
    text2=capitalizeWords(text1);
    cout<<"a mondat nagybetusitve "<<text2<<endl;
    //5 b
    //6 cod
    text1=code(text2);
    cout<<"A kodolt szoveg: "<<text1<<endl;
    text2=decode(text1);
    cout<<"A dekodolt szoveg: "<< text2<<endl;
    //7 split
    cout<<"szavak szama: "<<splitText(text2)<<endl;
    delete maxi;
    return 0;
}
