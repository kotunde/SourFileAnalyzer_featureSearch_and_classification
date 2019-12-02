#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <set>

#include "ponthalmaz.h"

#define M 2000

PontHalmaz::PontHalmaz(int n){
    if(n>=0){
        this->n=n;
    }
    int **p=new int*[M];
    for(int i=0; i<M; i++){
        p[i]=new int[M];
        for(int j=0; j<M; j++)
            p[i][j]=0;
    }
    int s=0;
    srand(time(0));
    while(s<n){
        int x,y;
        x=rand()%M;
        y=rand()%M;
        if(p[x][y]!=1){
            p[x][y]=1;
            s++;
            Pont P(x,y);
            this->pontok.push_back(P);
        }
    }
    for(int i=0; i<M; i++)
        delete(p[i]);
    delete(p);

    tavolsagSzamitas();
}

void PontHalmaz::tavolsagSzamitas(){
    for(int i=0; i<this->n; i++){
        Pont p1=this->pontok[i];
        for(int j=i+1; j<this->n; j++){
            Pont p2=this->pontok[j];
            double d=sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX()) + (p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
            this->tavolsagok.push_back(d);
        }
    }
}

double PontHalmaz::maxTavolsag() const{
    return *max_element(this->tavolsagok.begin(),this->tavolsagok.end());
}

double PontHalmaz::minTavolsag() const{
    return *min_element(this->tavolsagok.begin(),this->tavolsagok.end());
}

int PontHalmaz::tavolsagokSzama() const{
    return this->tavolsagok.size();
}

void PontHalmaz::printPontok() const{
    for(int i=0; i<this->n; i++)
        cout<<this->pontok[i].getX()<<","<<this->pontok[i].getY()<<endl;
}

void PontHalmaz::printTavolsagok() const{
    int N=this->tavolsagok.size();
    for(int i=0; i<N; i++)
        cout<<this->tavolsagok[i]<<endl;
}

bool hasonlitX(Pont p, Pont q){
    return (p.getX()<q.getX());
}

bool hasonlitY(Pont p, Pont q){
    return (p.getY()<q.getY());
}

void PontHalmaz::rendezPontokX(){
    sort(this->pontok.begin(),this->pontok.end(),hasonlitX);
}

void PontHalmaz::rendezPontokY(){
    sort(this->pontok.begin(),this->pontok.end(),hasonlitY);
}

void PontHalmaz::rendezTavolsagok(){
    sort(this->tavolsagok.begin(), this->tavolsagok.end());
}

int PontHalmaz::kulonbozoTavolsagokSzama(){
    //  Nem tudtam megcsinalni a UNIQUE hasznalataval
    /*
    vector<double>::iterator last=unique(this->tavolsagok.begin(), this->tavolsagok.end());
    //return distance(this->tavolsagok.begin(),last);
    this->tavolsagok.resize(distance(this->tavolsagok.begin(),last));
    return this->tavolsagok.size();
    */
    set<int>halmaz;
    int n=this->tavolsagok.size();
    for(int i=0; i<n;i++){
        halmaz.insert(tavolsagok[i]);
    }
    return halmaz.size();
}
