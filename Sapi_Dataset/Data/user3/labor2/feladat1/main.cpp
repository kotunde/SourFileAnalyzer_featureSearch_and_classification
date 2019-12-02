#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

#include "pont.h"
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {
        /*Pont p1(2,3);
        cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
        Pont p2(100, 200);
        cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
        Pont * pp1 = new Pont(300, 400);
        Pont * pp2 = new Pont(500, 1000);
        cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
        cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
        delete pp1;
        delete pp2;

*/
     cout<<"\n#1\n";
     ifstream fin;
     fin.open("pont_koordinatak_negyezt.txt");
     if(!fin){
        cout<<"file problem";
        return 0;
     }
     Pont p1,p2,p3,p4;
     int adat;
     while(fin>>adat){
        p1.setX(adat);
        fin>>adat; p1.setY(adat);
        fin>>adat; p2.setX(adat);
        fin>>adat; p2.setY(adat);
        fin>>adat; p3.setX(adat);
        fin>>adat; p3.setY(adat);
        fin>>adat; p4.setX(adat);
        fin>>adat; p4.setY(adat);
        cout<<p1.getX()<<","<<p1.getY()<<" - ";
        cout<<p2.getX()<<","<<p2.getY()<<" - ";
        cout<<p3.getX()<<","<<p3.getY()<<" - ";
        cout<<p4.getX()<<","<<p4.getY();
        if(isSquare(p1,p2,p3,p4))
            cout<<"\t-> negyzetet alkotnak\n";
        else
            cout<<"\t-> nem alkotnak negyzetet\n";
     }
     fin.close();

    //******************************************************
     cout<<"\n#2\n";
     int N=10,n=20;//N-pontok szama, n-(0,n)x(o,n) koordinatak
     Pont P[N];
     srand(time(0));
     distinctPointsGenerator(P,N,n);
     for(int i=0; i<N; i++)
        cout<<P[i].getX()<<","<<P[i].getY()<<endl;
     closestPair_bruteForce(P,N);
     farthestPair_bruteForce(P,N);

    //******************************************************
     cout<<"\n#3\n";
     cout<<"Rendezes X koordinata szerint:\n";
     rendezX(P,N);
     for(int i=0; i<N; i++)
        cout<<P[i].getX()<<","<<P[i].getY()<<endl;

     return (EXIT_SUCCESS);
}
