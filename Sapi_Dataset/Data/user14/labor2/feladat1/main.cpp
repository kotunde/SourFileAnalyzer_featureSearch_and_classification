#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "Pont.h"
#include <vector>
#include <algorithm>

bool negyzet(Pont, Pont, Pont, Pont);
using namespace std;


int main(int argc, char** argv)
{
    int x,y;
    cin >>x >>y;
    Pont A(x,y);
    cin >>x >>y;
    Pont B(x,y);
    cin >>x >>y;
    Pont C(x,y);
    cin >>x >>y;
    Pont D(x,y);
    cout <<"valasz: " << negyzet(A,B,C,D);
    return 0;
}

bool negyzet(Pont A, Pont B, Pont C, Pont D)
{
    if (!(A.getX()==B.getX() && A.getY()==B.getY()) && !(B.getX()==C.getX() && B.getY()==C.getY()) &&
        !(C.getX()==D.getX() && C.getY()==D.getY()) && !(D.getX()==A.getX() && D.getY()==A.getY()))
    {
        //double d1, d2, d3, d4, d5, d6;
        vector<double> distance;
        int i;
        distance.push_back(sqrt((B.getX()-A.getX())*(B.getX()-A.getX())+(B.getY()-A.getY())*(B.getY()-A.getY())));
        distance.push_back(sqrt((B.getX()-C.getX())*(B.getX()-C.getX())+(B.getY()-C.getY())*(B.getY()-C.getY())));
        distance.push_back(sqrt((D.getX()-C.getX())*(D.getX()-C.getX())+(D.getY()-C.getY())*(D.getY()-C.getY())));
        distance.push_back(sqrt((D.getX()-A.getX())*(D.getX()-A.getX())+(D.getY()-A.getY())*(D.getY()-A.getY())));
        distance.push_back(sqrt((C.getX()-A.getX())*(C.getX()-A.getX())+(C.getY()-A.getY())*(C.getY()-A.getY())));
        distance.push_back(sqrt((D.getX()-B.getX())*(D.getX()-B.getX())+(D.getY()-B.getY())*(D.getY()-B.getY())));
        sort(distance.begin(),distance.end());
//        for (i=0; i<6 ; ++i)
//        {
//            cout << distance[i] << " ";
//        }
        int ok=1;
        for (i=1; i<4; ++i)
        {
            //cout <<"tav " << i << " " << distance[i]<< " ";
            if (distance[i]!=distance[i-1])
            {
                ok=0;
            }
        }
        if (ok && distance[4]==distance[5])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}