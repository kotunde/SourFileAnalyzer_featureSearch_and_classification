#include "Functions.h"
#include "Pont.h"
#include <cstdbool>
#include <cmath>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;
bool negyzet(Pont a,Pont b,Pont c,Pont d)
{
    int t1= tav(a,b);
    int t2=tav(a,c);
    int t3=tav(a,d);
    int t4=tav(b,c);
    int t5=tav(b,d);
    int t6=tav(c,d);
    if(t1==t3&&t1==t4&&t1==t6&&t6==t4&&t4==t3&&t3==t6&&t2==t5)
    {
        cout<< "negyzet"<<endl;
        return true;
    }
    cout<< " nem negyzet"<<endl;
    return false;

}
int tav(Pont a,Pont b)
{
    int szum;
    szum=sqrt(((b.getY()-a.getY())*(b.getY()-a.getY()))+((b.getX()-a.getX())*(b.getX()-a.getX())));
    return szum;
}

void gen( int n )
{
   Pont t[n];
    srand(time(NULL));
    int i=0;
    while(i<n)
    {
        int g1=rand()%100+1;
        int g2=rand()%100+1;
        //if(matrix[g1][g2]==0)
       // {
            t[i].setX(g1);
            t[i].setY(g2);
           // matrix[g1][g2]=1;
        //}
        cout<<t[i].getX()<<"  "<<t[i].getY()<<endl;
        i++;
    }
    int e=0;
    int maxi=0;
    int mini=99999999;
    int e1,e2,e3,e4;
    int r1,r2,r3,r4;
    while(e<n)
    {
        for(int i=e; i<n-1; i++)
        {
            int d=tav(t[e],t[i+1]);
            if(d>maxi)
            {
                maxi=d;
                e1=t[e].getX();
                e2=t[e].getY();
                e3=t[i+1].getX();
                e4=t[i+1].getY();
            }
            if(d<mini)
            {
                mini=d;
                r1=t[e].getX();
                r2=t[e].getY();
                r3=t[i+1].getX();
                r4=t[i+1].getY();
            }
        }
        e++;
    }
    cout<<endl;
    cout<<"legnagyobb tavolsagu pontpar hossza "<<maxi<<"  pontjai "<<e1<<" "<<e2<<"     "<<e3<<" "<<e4<<"  legkisebb tavolsagu pontpar hossza "<<mini<<" pontjai "<<r1<<" "<<r2<<"       "<<r3<<" "<<r4;
    cout<<endl;
    sort(t,t+n,sortbyx);
}
/*void rendez(Pont t){
sort(t.begin(),t.end());
for(int i=0;i<t.size(),++i){
    cout<<t[i].getX();
}
}*/
bool sortbyx(Pont a,Pont b)
{
    return  a.getX()< b.getX();

}
/*Pont *origo(Pont *t,int n)
{
    int a[11];
    Pont t1[11];
    Pont o;
    o.setX()=0;
    o.getY()=0
    for(int i=0; i<n; i++)
    {
        int d1=tavolsag(o,t[i]);
        for(int j=0; j<10; j++)
            if(d1>a[j])
            {
                a[j]=d1;
                t1[j].setX(t[i].getX());
                t1[j].setY(t[i].getY());
                break;
            }
    }
    return t1;
}*/
/*Pont origo (Pont t[])
{


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
}*/
