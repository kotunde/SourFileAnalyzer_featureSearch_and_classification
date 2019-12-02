#include <cstdlib>
#include <iostream>
#include "Pont.h"
#include <fstream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main(int argc, char** argv) {
    int i,x,y,n, m=10000;
    Pont *a;
    a=(Pont*)malloc(m*sizeof(Pont));
 ifstream fin;
fin.open("bemenet.txt");
 fin >> n;

 for(i=0; i<n; ++i){
fin >> x >> y;
 Pont p1(x,y);
 fin >> x >> y;
 Pont p2(x,y);
 fin >> x >> y;
 Pont p3(x,y);
 fin >> x >> y;
 Pont p4(x,y);
 if(negyzet(p1,p2,p3,p4)==true){
    cout << i << ". sor negyzetet alkot!" << endl;
 }
 }
 srand(time(0));
 for(i=0; i<m; ++i){
    Pont s(rand()%2001,rand()%2001);
    a[i]=s;
 }
 rendez(a,m);




return 0;
}
