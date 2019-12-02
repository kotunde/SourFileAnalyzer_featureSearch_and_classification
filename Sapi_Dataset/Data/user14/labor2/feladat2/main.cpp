#include <iostream>
#define N 1000000
#define SIZE 2000
#define OSIZE 2004


#include "Pont.h"

#include <time.h>
#include <vector>
#include <cmath>
#include <chrono>


using namespace std;
using namespace std::chrono;



int main()
{
    bool ** table =(bool **) calloc(OSIZE, sizeof(bool*));
    if(!table)
    {
        printf("Memory allocating problem!");
        return(-1);
    }

    int loop;
    for(loop = 0; loop < OSIZE; ++loop)
    {
        table[loop] = (bool*) calloc(OSIZE,sizeof(bool));
        if(!table[loop])
        {
            printf("Memory allocating problem2!");
            return(-1);
        }
    }

    vector<Pont> *tomb= new vector<Pont>(N);

    srand(time(NULL));
    int i=0;
    while (i<N)
    {
        int temp1,temp2;
        temp1=rand()%SIZE;
        temp2=rand()%SIZE;
        if (table[temp1+2][temp2+2]==0)
        {
            table[temp1+2][temp2+2] = 1;
            (*tomb)[i].setX(temp1);
            (*tomb)[i].setY(temp2);
            ++i;
        }
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    cout<< "Legkisebb tavolsag:" << findmin(table,SIZE) << endl << endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    cout << "Legnagyobb tavolsag: " << findmax(table,SIZE) << endl << endl << endl;
    high_resolution_clock::time_point t4 = high_resolution_clock::now();


    auto duration1 = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "findmin: " << duration1 << " mikroszekundum"<<endl;

    auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();

    cout << "findmax: " << duration2 << " mikroszekundum" << endl << endl << endl;

    sorting(*tomb);
    Pont* tenpoints=findtenpoints(table,OSIZE);
    for (i=0; i<10; ++i)
    {
        cout << i<< ". "<<tenpoints[i].getX() << " "<< tenpoints[i].getY()<< endl;
    }



    ///lefoglalt tarolok felszabaditasa!!!
    for (i=0; i<OSIZE; ++i)
    {
        free(table[i]);
    }
    free(table);
    delete tomb;
    return 0;
}

