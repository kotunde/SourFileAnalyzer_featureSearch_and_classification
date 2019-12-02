#include "Pont.h"
#include <vector>
#include "PontHalmaz.h"
#include <vector>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define M 2000
#include<algorithm>
#include<iostream>
using namespace std;


void PontHalmaz::tavolsagSzamitas()
{
    int k=0;
    for(int i = 0; i < this->n; i++)
    {
        for(int j = i+1; j < this->n; j++)
        {

            tavolsagok.push_back(sqrt((pontok[i].getX()-pontok[j].getX()) * (pontok[i].getX()-pontok[j].getX()) + (pontok[i].getY()-pontok[j].getY()) * (pontok[i].getY()-pontok[j].getY())));
        }
    }
}

bool pontocskak[M][M]={true};
void nullaz(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            pontocskak[i][j]=true;
        }
    }
}

PontHalmaz::PontHalmaz(int n)
{
    this->n=n;
    srand(time(NULL));
    nullaz();
    while( pontok.size() < n )
    {
        //cout<<pontok.size()<<endl;
        int a = rand() % M;
        int b = rand() % M;
        if(pontocskak[a][b] == true){
            pontocskak[a][b] = false;
            Pont aux;
            aux.setX(a);
            aux.setY(b);
            pontok.push_back(aux);
        }
    }
    tavolsagSzamitas();

}

double PontHalmaz :: maxTavolsag() const
{
    return  *max_element(tavolsagok.begin(),tavolsagok.end());
}
double PontHalmaz :: minTavolsag() const
{
    return  *min_element(tavolsagok.begin(),tavolsagok.end());
}
int PontHalmaz :: tavolsagokSzama() const
{
    return (n * (n - 1)) / 2;
}

void PontHalmaz :: printPontok() const
{
    for(auto pont : pontok)
    {
        cout << pont.getX() << pont.getY() << endl;
    }
}

void PontHalmaz :: printTavolsagok() const
{
    for(auto tav : tavolsagok)
    {
        cout << tav <<endl;
    }
}

struct myclass
{
    bool operator() (Pont i,Pont j)
    {
        return (i.getX()<j.getX());
    }
} myobject;


void PontHalmaz :: rendezPontokX(){
    sort (pontok.begin(), pontok.end(), myobject);
}

struct myclass2
{
    bool operator() (Pont i,Pont j)
    {
        return (i.getY()<j.getY());
    }
} myobject2;

void PontHalmaz :: rendezPontokY(){
    sort (pontok.begin(), pontok.end(), myobject2);
}

struct myclass3
{
    bool operator() (double i,double j)
    {
        return (i<j);
    }
} myobject3;


void PontHalmaz :: rendezTavolsagok(){
    sort (tavolsagok.begin(), tavolsagok.end(), myobject3);
}

int PontHalmaz :: kulonbozoTavolsagokSzama(){
    rendezTavolsagok();
    double aux = tavolsagok[0];
    int db = 1;
    for(auto tav : tavolsagok)
    {
        if(aux != tav){
            db++;
            aux = tav;
        }
    }
    return db;
}


