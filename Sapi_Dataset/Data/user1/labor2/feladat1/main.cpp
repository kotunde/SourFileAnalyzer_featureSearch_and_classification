#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "Pont.h"
#include "functions.h"

using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("pontok.txt");
    int p[8];
    while (!myfile.eof()){
        for (int i = 0; i < 8; ++i){
            myfile >> p[i];
        }
        if (myfile.eof()){break;}
        Pont A(p[0],p[1]); Pont B(p[2],p[3]);
        Pont C(p[4],p[5]); Pont D(p[6],p[7]);
        cout << "A(" << A.getX() << " " << A.getY() << ") B(" << B.getX() << " " << B.getY() << ") C(" << C.getX() << " " << C.getY() << ") D(" << D.getX() << " " << D.getY() << ") pontok ";
        if (negyzet_e(A,B,C,D) == 0){
            cout << "nem alkotnak negyzetet." << endl;
        }
        else {
            cout << "negyzetet alkotnak." << endl;
        }
    }
    cout << endl;

    int n = 1000, i = 0;
    vector<Pont> pontok;

    srand(time(NULL));
    while (i < n){
        int x = rand() % 2001;
        int y = rand() % 2001;
        Pont A(x,y);
        //if (find(pontok.begin(),pontok.end(),A) != pontok.end()){
        //    pontok.push_back(A); ++i;}
        pontok.push_back(A); ++i;
    }

    sort(pontok.begin(),pontok.end(),compareX);

    /*for (int i = 0; i < n; ++i){
        cout << a[i].getX() << " " << a[i].getY() << endl;
    }
    cout << endl;*/

    vector<Pont> lk = legkozelebbi(pontok,n);
    cout << "Legkozelebbi pont par: " << endl;
    for (int i = 0; i < 2; ++i){
        cout << "(" << lk[i].getX() << "," << lk[i].getY() << ")";
    }
    cout << " Tavolsag: " << tavolsag(lk[0],lk[1]) << endl;

    cout << "Legtavolabbi pont par: " << endl;
    vector<Pont> lt = legtavolabbi(pontok,n);
    for (int i = 0; i < 2; ++i){
        cout << "(" << lt[i].getX() << "," << lt[i].getY() << ")";
    }
    cout << " Tavolsag: " << tavolsag(lt[0],lt[1]) << endl;

    vector<Pont> lt_tiz = legtavolabbi_tiz(pontok,n);
    cout << "Tiz legtavolabbi pont: " << endl;
    for (int i = 0; i < 10; ++i){
        cout << lt_tiz[i].getX() << " " << lt_tiz[i].getY() << endl;
    }

    return 0;
}
