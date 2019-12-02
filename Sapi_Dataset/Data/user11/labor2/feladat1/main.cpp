#include <cstdlib>
#include <iostream>
#include "Pont.h"
#include "Functions.h"
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
 Pont p1(2,3);
 cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
 Pont p2(100, 200);
 cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
 Pont * pp1 = new Pont(300, 400);
 Pont * pp2 = new Pont(500, 1000);
 cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
 cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
 Pont a(10,10);
 Pont b(10,20);
 Pont c(20,20);
 Pont d(20,10);
int t1=0;
t1=tav(a,b);
cout<<t1<<endl;
 cout<<negyzet(a,b,c,d)<<endl;
 int n=2000;
 gen(n);
/*Pont *w=origo(gen(n),n);
    for(int i=0; i<10; i++)
    {
        cout<<w[i].getX()<<"   "<<w[i].getY()<<endl;
    }
}*/
 delete pp1;
 delete pp2;
 return 0;
}
