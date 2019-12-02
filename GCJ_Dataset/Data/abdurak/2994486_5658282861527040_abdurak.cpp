/*
* abdurak
* Google CodeJam 2014 - Round 1B
* Problem B
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
#define FORN(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FORR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
int main(){
    ifstream fin("B.in");
    ofstream fout("B.out");
    //fout<<setprecision(15);
    int T;
    fin>>T;
    FORR(iT,1,T){
        fout<<"Case #"<<iT<<": ";
        int A,B,K;
        long long n=0;
        fin>>A>>B>>K;
        FORN(i,A){
                  FORN(j,B){
                            if((i&j)<K){
                                      n++;
                                      }
                            }
                  }
        fout<<n;
        fout<<endl;
    }
    system("pause");
}
