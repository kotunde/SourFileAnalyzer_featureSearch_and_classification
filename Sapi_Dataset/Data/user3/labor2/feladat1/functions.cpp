#include <iostream>
#include <math.h>
#include <limits.h>
#include <algorithm>

#include "functions.h"

using namespace std;

int distanceSquare(Pont p1, Pont p2){
    return (p1.getX()-p2.getX())*(p1.getX()-p2.getX()) + (p1.getY()-p2.getY())*(p1.getY()-p2.getY());
}

bool isSquare(Pont p1, Pont p2, Pont p3, Pont p4){
    if(p1.getX()==p2.getX() && p1.getX()==p3.getX() && p1.getX()==p4.getX()
        && p1.getY()==p2.getY() && p1.getY()==p3.getY() && p1.getY()==p4.getY())
        return false;

    int d1,d2,d3,d4;//oldalak
    d1=distanceSquare(p1,p2);
    d2=distanceSquare(p2,p3);
    d3=distanceSquare(p3,p4);
    d4=distanceSquare(p4,p1);

    if(d1!=d2 || d1!=d3 || d1!=d4)//egyenlo hosszusagu oldalak
        return false;

    int D1,D2;//atlo
    D1=distanceSquare(p1,p3);
    D2=distanceSquare(p2,p4);

    if(D1 != D2)//egyenlo hosszusagu atlok
        return false;

    //szogek - pitagorasz
    if(d1+d2 != D1)
        return false;
    if(d2+d3 != D2)
        return false;
    if(d3+d4 != D1)
        return false;
    if(d4+d1 != D2)
        return false;

    return true;
}

void distinctPointsGenerator(Pont P[],int N, int n){
    int i=0;
    int** pontok=(int**)calloc(n,sizeof(int*));
    for(int i=0; i<n; i++)
        pontok[i]=(int*)calloc(n,sizeof(int));
    while(i<N){
        int x,y;
        x=rand()%n;
        y=rand()%n;
        if(pontok[x][y]!=1){
            pontok[x][y]=1;
            Pont p(x,y);
            P[i]=p;
            i++;
        }
    }
    for(int i=0; i<n; i++)
        free(pontok[i]);
    free(pontok);
}

void closestPair_bruteForce(Pont P[],int N){
    int minDist=INT_MAX;
    Pont p,q;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int d=distanceSquare(P[i],P[j]);
            if(d<minDist){
                minDist=d;
                p=P[i];
                q=P[j];
            }
        }
    }
    cout<<"Legkozelebbi pontpar: "<<p.getX()<<","<<p.getY()<<" - "<<q.getX()<<","<<q.getY()<<endl;
}

void farthestPair_bruteForce(Pont P[],int N){
    int maxDist=INT_MIN;
    Pont p,q;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int d=distanceSquare(P[i],P[j]);
            if(d>maxDist){
                maxDist=d;
                p=P[i];
                q=P[j];
            }
        }
    }
    cout<<"Legtavolabbi pontpar: "<<p.getX()<<","<<p.getY()<<" - "<<q.getX()<<","<<q.getY()<<endl;
}

bool hasonlit(Pont p, Pont q){
    return (p.getX()<q.getX());
}

void rendezX(Pont P[], int N){
    sort(&P[0],&P[N],hasonlit);
}
