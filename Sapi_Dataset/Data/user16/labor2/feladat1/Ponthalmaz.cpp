#include "Ponthalmaz.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

bool myfunction2 (const Pont & a,const Pont  & b)
{
    return (a.getY()<b.getY());
}

bool myfunction (const Pont & a,const Pont  & b)
{
    return (a.getX()<b.getX());
}

void kiir (vector<Pont> pontok)
{
    for (auto & v : pontok)
    {
        cout<<"( "<<v.getX()<<" , "<<v.getY()<<" )"<<endl;
    }
    cout<<endl<<endl;
}


void rendez2 (vector<Pont> pontok)
{
    sort(pontok.begin(),pontok.end(),myfunction2);
    //kiir(pontok);
}

void rendez (vector<Pont> pontok)
{
    sort(pontok.begin(),pontok.end(),myfunction);
    //kiir(pontok);
}




vector<Pont> felvesz (int N)
{
    int ** t = new int * [2001];
    for (int i = 0 ; i<2001 ; i++)
        t[i] = new int [2001];

    int x, y, k = N;
    vector<Pont> pontok;
    srand(time(NULL));
    while (k)
    {
        x = rand() % 2001;
        y = rand() % 2001;
        if (!t[x][y])
        {
            pontok.push_back(Pont (x,y));
            t[x][y] = 1;
            k--;
        }
        else
            continue;
    }
    return pontok;
}


double dist (const Pont & a, const Pont & b)
{
    return (sqrt((a.getX()-b.getX())*(a.getX()-b.getX()) + (a.getY()-b.getY())*(a.getY()-b.getY())));
}

PontHalmaz::PontHalmaz( int n )
{
    this->n = n;
    this->pontok = felvesz(n);
    tavolsagSzamitas();
}

void PontHalmaz :: tavolsagSzamitas ()
{
    for (int i = 0 ; i<this->pontok.size(); i++)
        for (int j = i+1 ; j<this->pontok.size(); j++)
            this->tavolsagok.push_back(dist(this->pontok[i],this->pontok[j]));
}

double PontHalmaz :: maxTavolsag() const
{
    return *max_element(this->tavolsagok.begin(),this->tavolsagok.end());
}

double PontHalmaz :: minTavolsag() const
{
    return *min_element(this->tavolsagok.begin(),this->tavolsagok.end());
}

int PontHalmaz :: tavolsagokSzama() const
{
    return (this->tavolsagok.size());
}

void PontHalmaz :: printPontok() const
{
    kiir(this->pontok);
}

void PontHalmaz :: printTavolsagok() const
{
    for (int i = 0 ; i<this->tavolsagok.size(); i++)
        cout<<tavolsagok[i]<<endl;
}

void PontHalmaz ::rendezPontokX()
{
    rendez(this->pontok);
}

void PontHalmaz ::rendezPontokY()
{
    rendez2(this->pontok);
}

bool comp (double a, double b)
{
    return (a<b);
}

void PontHalmaz :: rendezTavolsagok()
{
    sort(this->tavolsagok.begin(),this->tavolsagok.end(),comp);
}
int PontHalmaz :: kulonbozoTavolsagokSzama()
{
    set <double> v  (this->tavolsagok.begin(),this->tavolsagok.end());
    return v.size();
}
