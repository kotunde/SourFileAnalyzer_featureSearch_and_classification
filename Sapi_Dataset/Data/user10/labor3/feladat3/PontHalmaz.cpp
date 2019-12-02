#include "PontHalmaz.h"
#include <random>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <iostream>

bool foglalt[2001][2001] {false};

PontHalmaz::PontHalmaz( int n ){
    srand(time(NULL));
    this->n = n;
    for(auto& sor: foglalt) for(auto& elem: sor) elem = false;
    for(int i=0; i<n; ++i){
        int newX = rand()%2001;
        int newY = rand()%2001;
        while(foglalt[newX][newY]){
            newX = rand()%2001;
            newY = rand()%2001;
        }
        this->pontok.push_back(Pont(newX,newY));
        foglalt[newX][newY] = true;
    }
    this->tavolsagSzamitas();
};
double distance(const Pont& a, const Pont& b){
    int dx=a.getX()-b.getX();
    int dy=a.getY()-b.getY();
    return sqrt(dx*dx+dy*dy);
};
void PontHalmaz::tavolsagSzamitas(){
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j)
            tavolsagok.push_back(distance(pontok[i],pontok[j]));
    this->rendezTavolsagok();
};
double PontHalmaz::maxTavolsag() const{return *tavolsagok.rbegin();};
double PontHalmaz::minTavolsag() const{return *tavolsagok.begin();};
int PontHalmaz::tavolsagokSzama() const{return tavolsagok.size();};
void PontHalmaz::printPontok() const{
    for(auto& elem: pontok)
        std::cout << "Pont: (" << elem.getX() << "|" << elem.getY() << ")\n";
};
void PontHalmaz::printTavolsagok() const{
    for(auto& elem: tavolsagok)
        std::cout << "Tavolsag: " << elem << std::endl;
};
void PontHalmaz::rendezPontokX(){ std::sort(pontok.begin(),pontok.end(), [](Pont a, Pont b)->int{ return a.getX()<b.getX(); }); };
void PontHalmaz::rendezPontokY(){ std::sort(pontok.begin(),pontok.end(), [](Pont a, Pont b)->int{ return a.getY()<b.getY(); }); };
void PontHalmaz::rendezTavolsagok(){ std::sort(tavolsagok.begin(),tavolsagok.end(), [](double a, double b)->int{ return a<b; }); };
int PontHalmaz::kulonbozoTavolsagokSzama(){
    int counter = 0;
    double elozo = 0;
    for(auto& tav: tavolsagok)
        if(tav != elozo){
            ++counter;
            elozo = tav;
        }
    return counter;
};

