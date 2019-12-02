#include "PontHalmaz.h"
#include "Pont.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cmath>
using namespace std;

PontHalmaz( int n = 100 ){
    srand(0);
    int N=2001;
    this->n=n;
    int i,x,y,j;
    vector<bool> v(N*N,false);
    for(i=0,i<this->n;++i){
        x=rand()%N;
        y=rand()%N;
        if(! v[y*N+x]){
            pontok.push_back(Pont(x,y));
            b[y*N+x];
        }
        else{
            --i;
        }
    }
   for(i=0;i<this->n-1;++i){
    for(j=i+1;j<this->n;++i){
        if(i!=j){
            tavolsagok.push_back(tavolsag(pontok[i],pontok[j]));

        }
    }
   }
}

/*void tavolsagSzamitas(){

    int szum;
    vector<Pont> pontok;

    Pont p,q;
    szum=sqrt(((p.getY()-q.getY())*(p.getY()-q.getY()))+((p.getX()-q.getX())*(p.getX()-q.getX())));
    vector<double> tavolsagok;
    tavolsagok.push_back(szum);
}*/


double maxTavolsag()//maximum kiválasztás a tavolsag tömbbõl
 {
     return  *max_element(tavolsagok.begin(),tavolsagok.end())
 }
 double minTavolsag() //minimum kiválasztás a tavolsag tömbbõl
 {
        return  *min_element(tavolsagok.begin(),tavolsagok.end())
 }
 int tavolsagokSzama()
 {
     return tavolsagok.size()

 }
 void printPontok()  //a pontok tároló kiíratása
 {
     for( int i=0; i<pontok.size(); ++i ){
        cout<<pontok [ i]<<endl;

     }
 }
 void printTavolsagok()
 {
      for( int i=0; i<pontok.size(); ++i ){
        cout<<tavolsagok[ i]<<endl;

     }

 }
  /*void rendezPontokX(){

  }
   void rendezPontokY(){

   }
   void rendezTavolsagok(){

   }*/
   int kulonbozoTavolsagokSzama(){
    sort(tavolsagok.begin(),tavolsagok.end());
    return unique((tavolsagok.begin(),tavolsagok.end())-tavolsagok.begin());
   }
double tavolsag(Pont& p,Pont& q){
return sqrt(((p.getY()-q.getY())*(p.getY()-q.getY()))+((p.getX()-q.getX())*(p.getX()-q.getX())));
}
