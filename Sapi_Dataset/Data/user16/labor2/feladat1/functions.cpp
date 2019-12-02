#include "functions.h"

#include <math.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

bool negyzet (const Pont * a)
{
    double dist1,dist2,dist3;
    dist1 = dist(a[0],a[1]);
    dist2 = dist(a[0],a[2]);
    dist3 = dist(a[0],a[3]);

    if ((dist1 == dist2) && dist3 ==dist1*sqrt(2))
        return true;
    if ((dist1 == dist3) && dist2 ==dist1*sqrt(2))
        return true;
    if ((dist2 == dist3) && dist1 ==dist2*sqrt(2))
        return true;

    return false;

}

double dist (const Pont & a, const Pont & b)
{
    return (sqrt((a.getX()-b.getX())*(a.getX()-b.getX()) + (a.getY()-b.getY())*(a.getY()-b.getY())));
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

int compare (const void *a, const void *b)
{
    const Pont * x = (const Pont*) a;
    const Pont * y = (const Pont*) b;
    return (dist(Pont (0,0),*x) - dist(Pont(0,0),*y));
}

int compare2 (const void *a, const void *b)
{
    return *(double *)a - *(double *)b;
}


bool myfunction (const Pont & a,const Pont  & b)
{
    return (a.getX()<b.getX());
}

bool myfunction2 (const Pont & a,const Pont  & b)
{
    return (a.getY()<b.getY());
}

void rendez (vector<Pont> pontok)
{
    sort(pontok.begin(),pontok.end(),myfunction);
    //kiir(pontok);
}

void kiir (vector<Pont> pontok)
{
    for (auto & v : pontok)
    {
        cout<<"( "<<v.getX()<<" , "<<v.getY()<<" )"<<endl;
    }
    cout<<endl<<endl;
}

void legtavolabbiak (vector<Pont> pontok)
{

    double * tavolsagok = new double[pontok.size()];
    for (int i = 0 ; i<pontok.size(); i++)
    {
        tavolsagok[i] = dist(Pont(0,0),pontok[i]);
    }

    qsort(tavolsagok,pontok.size(),sizeof(double),compare2);

    qsort(&pontok[0],pontok.size(),sizeof(Pont),compare);
    for (int i = pontok.size()-1; i>=pontok.size()-10; i--)
        cout<<"( "<<pontok[i].getX()<<" , "<<pontok[i].getY()<<" )   tavolsag = "<<dist(Pont(0,0),pontok[i])<<endl;

    cout<<endl<<endl;

    for (int i = pontok.size()-1; i>=pontok.size()-10; i--)
    {
        cout<<tavolsagok[i]<<endl;
    }

}

void legk(vector<Pont> pontok)
{
    int poz1 = 0, poz2 = 0;
    double maxi = 0, mini =1000000;
    for (int i = 0 ; i<pontok.size(); i++)
    {
        for (int j = 0 ; j<pontok.size(); j++)
        {
            if (dist(pontok[i],pontok[j])>maxi)
            {
                maxi = dist(pontok[i],pontok[j]);
                poz1 = i;
                poz2 = j;
            }
        }
    }
    cout<<endl<<"Legtavolabbi pontok : "<<" ( "<<pontok[poz1].getX()<<" , "<<pontok[poz1].getY()<<" ) es ( "<<pontok[poz2].getX()<<" , "<<pontok[poz2].getY()<<" ) tavolsag = "<<maxi<<endl;

    poz1=poz2=0;
    for (int i = 0 ; i<pontok.size(); i++)
    {
        for (int j = 0 ; j<pontok.size(); j++)
        {
            if (dist(pontok[i],pontok[j])<mini && i!=j)
            {
                mini = dist(pontok[i],pontok[j]);
                poz1 = i;
                poz2 = j;
            }
        }
    }

    cout<<endl<<"Legkozelebbi pontok : "<<" ( "<<pontok[poz1].getX()<<" , "<<pontok[poz1].getY()<<" ) es ( "<<pontok[poz2].getX()<<" , "<<pontok[poz2].getY()<<" ) tavolsag = "<<mini<<endl;

}

void rendez2 (vector<Pont> pontok)
{
    sort(pontok.begin(),pontok.end(),myfunction2);
    //kiir(pontok);
}

