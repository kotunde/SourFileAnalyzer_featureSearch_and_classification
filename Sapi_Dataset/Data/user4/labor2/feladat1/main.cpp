#include <cstdlib>
#include <iostream>
#include "Pont.h"
#include "functions.h"
#include<stdlib.h>
#include<time.h>
#include <algorithm>
#include <fstream>
#define M 20
using namespace std;
int main(int argc, char** argv)
{
    int x, y;
    ifstream ifs("be.txt");
    while(ifs >> x)
    {
        ifs >> y;
        Pont a (x,y);
        cout << x << " " << y <<" ";
        ifs >> x >> y;
        Pont b (x,y);
        cout << x << " " << y <<" ";
        ifs >> x >> y;
        Pont c (x,y);
        cout << x << " " << y <<" ";
        ifs >> x >> y;
        Pont d (x,y);
        cout << x << " " << y <<" " << endl;
        if(negyzet(a,b,c,d))
        {
            cout << "Negyzet" << endl;
        }
        else
        {
            cout << "Nem negyzet" << endl;
        }
    }



    int N=10;
    Pont * pontok;
    pontok = (Pont*)malloc(N*sizeof(Pont));

    srand(time(NULL));

    pontok[0].setX(rand() % M);
    pontok[0].setY(rand() % M);
    for(int i = 1; i < N; i++)
    {
        pontok[i].setX(rand() % M);
        pontok[i].setY(rand() % M);
        for(int j = 0; j < i; j++)
        {
            if(hasonlit(pontok[j],pontok[i]))
            {
                i--;
                j=i;
            }
        }

    }
    //for(int i = 1; i < N; i++){
    //   cout<<"p"<<i<<"( "<<pontok[i].getX()<<","<<pontok[i].getY()<<")"<<endl;
    //}
    double* minimax=legkissebblegnagyobbTav(pontok,N);
    cout << "A legkissebb tav = "<<minimax[0] << endl;
    cout << "A legnagyobb tav = "<<minimax[1] << endl;

    sort(pontok, pontok + N, rendezesHasonlito);

    for(int i = 1; i < N; i++)
    {
        cout<<"p"<<i<<"( "<<pontok[i].getX()<<","<<pontok[i].getY()<<")"<<endl;
    }
    return (EXIT_SUCCESS);
}
