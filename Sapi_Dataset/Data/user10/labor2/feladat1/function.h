#ifndef FUNCTION_H
#define FUNCTION_H

#include "Pont.h"
#include <math.h>
#include <sstream>
#include <algorithm>

std::stringstream szemet("");

double distance(const Pont& a, const Pont& b){
    int dx=a.getX()-b.getX();
    int dy=a.getY()-b.getY();
    double tav = sqrt(dx*dx+dy*dy);
    szemet << tav;///cheat XD
    szemet.clear();
    return tav;
};

bool IsSquare(const Pont& a, const Pont& b, const Pont& c, const Pont& d){
    if(distance(a,b) != distance(c,d)) return false;
    if(distance(a,d) != distance(c,b)) return false;
    double AC = distance(a,c);
    if(AC != distance(b,d)) return false;
    return AC;
};

bool comp_pont(Pont a,Pont b){
    if(a.getX() == b.getX()) return a.getY() < b.getY();
    return a.getX() < b.getX();
};

Pont* dot_generator1(int N,int limitX, int limitY){
    ///if(pontok) delete[] pontok;
    Pont* pontok = new Pont[N];
    bool foglalt;
    for(int i=0; i<N; ++i){
        foglalt = true;
        Pont UJ;
        while(foglalt){
            UJ = Pont(rand()%limitX,rand()%limitY);
            foglalt = std::binary_search(pontok,pontok+i,UJ,comp_pont);
            if(foglalt) std::cout << "F ";
        }
        if(i%1000==999) std::cout << "kesz:" << i+1 << std::endl;
        pontok[i] = UJ;
        std::sort(pontok,pontok+i+1,comp_pont);
    }
    /*
    for(int i=0; i<N; ++i){
        cout << i+1 << ".\tpont |" "X: " << pontok[i].getX() << "\tY: " << pontok[i].getY() << endl;
    }
    //*/
    return pontok;
}

Pont* dot_generator2(int N,int limitX, int limitY){
    ///if(pontok) delete[] pontok;
    Pont* pontok = new Pont[N];
    bool** foglalt = new bool*[limitX];//
    for(int i=0; i<limitX; ++i){
        foglalt[i] = new bool[limitY];
        for(int j=0; j<limitY; ++j) foglalt[i][j] = false;
    }
    for(int i=0; i<N; ++i){
        int newX = rand()%limitX;
        int newY = rand()%limitY;
        while(foglalt[newX][newY]){
            newX = rand()%limitX;
            newY = rand()%limitY;
        }
        if(i%1000==999) std::cout << "kesz:" << i+1 << std::endl;
        pontok[i] = Pont(newX,newY);
        foglalt[newX][newY] = true;
    }
    for(int i=0; i<limitX; ++i) delete[] foglalt[i];
    delete[] foglalt;
    std::sort(pontok,pontok+N,comp_pont);
    ///for(int i=N-10000; i<N; ++i) std::cout << i+1 << ".\tpont |" "X: " << pontok[i].getX() << "\tY: " << pontok[i].getY() << std::endl;

    return pontok;
}

#endif // FUNCTION_H_INCLUDED
