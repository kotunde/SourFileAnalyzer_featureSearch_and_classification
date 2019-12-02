#include "ponthalmaz.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Pont.h"
#define N 2001
#define FLT_EPSILON 1.19209290E-07F

bool fuggvenyem (double i, double j);
bool Xszerint (Pont& i, Pont& j);
bool Yszerint (Pont& i, Pont& j);
double tav(Pont a, Pont b);
bool matrix[N][N];

void matrixinicializalas()
{
    matrix[N][N] = {false};
}

PontHalmaz::PontHalmaz( int n )
{
    matrixinicializalas();
    int i=0, x, y;
    this->n = n;
    srand(time(0));
    while (i<n) {
        x = rand() % (2000 - 0 +1);
        y = rand() % (2000 - 0 +1);
        if ( !matrix[x][y] ) {
            this->pontok.push_back(Pont(x,y));
            matrix[x][y] = true;
            ++i;
            //if(i%1000==1)cout<<" i:"<<i<<" ";
        }
    }

    tavolsagSzamitas();

}

double PontHalmaz::maxTavolsag() const{
    return *max_element(tavolsagok.begin(), tavolsagok.end());
}

double PontHalmaz::minTavolsag() const
{
    return *min_element(tavolsagok.begin(), tavolsagok.end());
}

void PontHalmaz::printPontok() const
{
    for (auto& x : this->pontok) {
        cout<<"("<<x.getX()<<", "<<x.getY()<<")"<<endl;
    }
}

void PontHalmaz::printTavolsagok() const
{
    for (auto& x : this->tavolsagok) {
        cout<<x<<endl;
    }
}

bool fuggvenyem (double A, double B) {
    // a kulonbseg kiszamitasa
    float maxRelDiff = FLT_EPSILON;
    float diff = fabs(A - B);
    A = fabs(A);
    B = fabs(B);
    // melyik a nagyobb
    float largest = (B > A) ? B : A;

    if (diff <= largest * maxRelDiff)
        return true;
    return false;
  //return (i==j);
}

bool Xszerint (Pont& i, Pont& j) {
  return i.getX()<j.getX();
}
bool Yszerint (Pont& i, Pont& j) {
  return i.getY()<j.getY();
}

int PontHalmaz::kulonbozoTavolsagokSzama()
{
    return distance(tavolsagok.begin(),(unique(tavolsagok.begin(),tavolsagok.end(),fuggvenyem)));
}

void PontHalmaz::rendezPontokX()
{
   sort(pontok.begin(),pontok.end(),Xszerint);

}

void PontHalmaz::rendezPontokY()
{
   sort(pontok.begin(),pontok.end(),Yszerint);
}

double tav(Pont a, Pont b)
{
    double A = (b.getX()-a.getX())*(b.getX()-a.getX());
    double B = (b.getY()-a.getY())*(b.getY()-a.getY());
    return sqrt(A+B);
}

void PontHalmaz::tavolsagSzamitas()
{
    for(int i=0; i<this->n-1; i++){
            for(int j=i+1;j<n;j++){
                    tavolsagok.push_back(tav(pontok.at(i), pontok.at(j)));
            }
    }
}

int PontHalmaz::tavolsagokSzama() const
{
    return tavolsagok.size();
    //return (n*(n-1))/2;
}
