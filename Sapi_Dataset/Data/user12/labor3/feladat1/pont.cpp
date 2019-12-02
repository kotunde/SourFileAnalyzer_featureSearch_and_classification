#include <vector>
#include "Pont.h"
#include <time.h>
#include "header.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

bool cmp_x(const Pont &a, const Pont &b);
bool cmp_y(const Pont &a, const Pont &b);

PontHalmaz::PontHalmaz(int n){
srand(time(0));
    int i,j;
this->n =n;
for(i=0; i<n; ++i){
    Pont s(rand()%2001,rand()%2001);
    this -> pontok.push_back(s);

}
for(i=0; i<n-1; ++i){
    for(j=i+1; j<n; ++j){
      this -> tavolsagok.push_back(distance(pontok[i], pontok[j]));
}
}
}
double PontHalmaz::maxTavolsag()const{
    return *max_element(tavolsagok.begin(),tavolsagok.end());
}
double PontHalmaz::minTavolsag()const{
   return *min_element(tavolsagok.begin(),tavolsagok.end());
}

int PontHalmaz::tavolsagokSzama()const{
return tavolsagok.size();
}

void PontHalmaz::printPontok()const{
int i;
for(i=0; i<this->pontok.size(); ++i){
    cout << this->pontok[i].getX() << " " << this->pontok[i].getY() << endl;
}
}

void PontHalmaz::printTavolsagok()const{
int i;
for(i=0; i<this->tavolsagok.size(); ++i){
    cout << this->tavolsagok[i] << " " << endl;
}
}

void PontHalmaz::rendezPontokX(){
sort(this->pontok.begin(), this->pontok.end(),cmp_x);
}

void PontHalmaz::rendezPontokY(){
sort(this->pontok.begin(), this->pontok.end(),cmp_y);
}

bool cmp_x(const Pont &a, const Pont &b){
return a.getX()<b.getX();
}

bool cmp_y(const Pont &a, const Pont &b){
return a.getY()<b.getY();
}

void PontHalmaz::rendezTavolsagok(){
sort(this->tavolsagok.begin(),this->tavolsagok.end());
}

int PontHalmaz::kulonbozoTavolsagokSzama(){
   return ((unique(this->tavolsagok.begin(),this->tavolsagok.end())) - (this->tavolsagok.begin()));

}
