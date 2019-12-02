#include "Pont.h"
#include <cmath>
#include <algorithm>
Pont::Pont(int x, int y) {
 if (x >= 0 && x <= 2000) this->x = x;
 else
 this->x = 0;
 if (y >= 0 && y <= 2000) this->y = y;
 else
 this->y = 0;
}
int Pont::getX() const {
 return x;
}
int Pont::getY() const {
 return y;
}
void Pont::setX(int x) {
 if (x >= 0 && x <= 2000) this->x = x;
}
void Pont::setY(int y) {
 if (y >= 0 && y <= 2000) this->y = y;
}
void Pont::move(int nx, int ny) {
 if (nx >= 0 && nx <= 2000 && ny >= 0 && ny <= 2000) {
 this->x = nx;
 this->y = ny;
 }
}
double distance(Pont a, Pont b){
int dx = a.getX()-b.getX();
int dy = a.getY()-b.getY();
return sqrt(dx*dx+dy*dy);
}
bool negyzet(Pont p1, Pont p2, Pont p3, Pont p4){
int a[6],i,j,v;
a[0]=distance(p1,p2);
a[1]=distance(p2,p3);
a[2]=distance(p3,p4);
a[3]=distance(p4,p1);
a[4]=distance(p1,p3);
a[5]=distance(p4,p2);

for(i=0; i<5; ++i){
    for(j=i+1; j<6; ++j){
        if(a[i]>a[j]){
            v=a[j]; a[i]=a[j]; a[j]=v;
        }
    }
}

if(a[0]==a[3] && a[4]==a[5] && a[5]>a[0]){
    return true;
}
else{
    return false;
}

}

void rendez(Pont* a,int n){
    int i,j,s=0,v;
    double *b=(double*)malloc(n*n*sizeof(double));
    for(i=0; i<n-1; ++i){
        for(j=i+1; j<n; ++j){
            b[s]=distance(a[i],a[j]);
        }
    }
    for(i=0; i<n*n; ++i){
    for(j=i+1; j<n*n; ++j){
        if(b[i]>b[j]){
            v=b[j]; b[i]=b[j]; b[j]=v;
        }
    }
    }
}

