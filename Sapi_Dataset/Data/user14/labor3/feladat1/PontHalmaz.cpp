//PontHalmaz
// Created by tuni on 10/8/18.
//

#include "PontHalmaz.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>


PontHalmaz::PontHalmaz(int n)
{
    this->n=n;
    int x,y;
    srand(time(NULL));
    Pont temp;
    //cout << n;
    for (auto it=0; it<this->n; ++it)
    {
        x=rand()%2001;
        y=rand()%2001;
        temp.setX(x);
        temp.setY(y);
        Pontok.push_back(temp);
    }
    tavolsagSzamitas();
}

void PontHalmaz::tavolsagSzamitas()
{
    int i, j;
    for (i = 0; i < this->n-1; ++i) {
        for (j = i+1; j < this->n; ++j) {
            tavolsagok.push_back(sqrt((Pontok[j].getX()-Pontok[i].getX())*(Pontok[j].getX()-Pontok[i].getX())+(Pontok[j].getY()-Pontok[i].getY())*(Pontok[j].getY()-Pontok[i].getY())));
        }

    }
}

double PontHalmaz::maxTavolsag() const {
    double maxtav=tavolsagok[0];
    for (auto& t:tavolsagok)
    {
        if (t>maxtav)
        {
            maxtav=t;
        }
    }
    return maxtav;
}

double PontHalmaz::minTavolsag() const
{
    double mintav=tavolsagok[0];
    for (auto& t:tavolsagok)
    {
        if (t<mintav)
        {
            mintav=t;
        }
    }
    return mintav;
}

int PontHalmaz::tavolsagokSzama() const
{
    return ((n*(n-1))/2);
}

void PontHalmaz::printPontok() const
{
    for (auto& i:Pontok)
    {
        cout<< "x "<< i.getX() <<" y "<< i.getY()<<endl;
    }
}

void PontHalmaz::printTavolsagok() const
{
    cout<<tavolsagok.size() <<endl;
    cout <<"Tavolsagok:\n";
    for (auto& i:tavolsagok)
    {
        cout<< i << ", ";
    }
}

bool cmp1(Pont a,Pont b)
{
    return(a.getX()<b.getX());
}

void PontHalmaz::rendezPontokX()
{
    sort(Pontok.begin(),Pontok.end(),cmp1);
}

bool cmp2(Pont a,Pont b)
{
    return(a.getY()<b.getY());
}

void PontHalmaz::rendezPontokY()
{
    sort(Pontok.begin(),Pontok.end(),cmp2);
}

void PontHalmaz::rendezTavolsagok()
{
    sort(tavolsagok.begin(),tavolsagok.end());
}

int PontHalmaz::kulonbozoTavolsagokSzama()
{
    unordered_set<double> tavset;
    for( auto& i:tavolsagok)
    {
        tavset.insert(i);
    }
    return tavset.size();
}
