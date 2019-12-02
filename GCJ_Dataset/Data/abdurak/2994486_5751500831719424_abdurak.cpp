/*
* abdurak
* Google CodeJam 2014 - Round 1B
* Problem A
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
#define FORN(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FORR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
int main(){
    ifstream fin("A.in");
    ofstream fout("A.out");
    //fout<<setprecision(15);
    int T;
    fin>>T;
    FORR(iT,1,T){
        fout<<"Case #"<<iT<<": ";
        int N;
        vector<string> strings;
        int pts[100]={0};
        fin>>N;
        string foo;
        getline(fin,foo);
        FORN(i,N){
                  getline(fin,foo);
                  strings.push_back(foo);
        }
        char ch=strings[0][0];
        int flag=1,totalhamle=0;
        while(pts[0]<strings[0].length() && flag==1){
                 int artis[100]={0},totartis=0;
                 FORN(i,N){
                           if(strings[i][pts[i]]!=ch) {flag=0;}
                           while(strings[i][pts[i]]==ch){
                                                         artis[i]++;
                                                         totartis++;
                                                         pts[i]++;
                           }
                           //cout<<pts[i]<<endl;
                 }
                 int hamle=0;
                 FORN(i,N){
                           hamle+=abs(artis[i]-totartis/N);
                 }
                 //cout<<hamle<<endl;
                 totalhamle+=hamle;
                 ch=strings[0][pts[0]];
                 //system("pause");
        }
        FORN(i,N){
                  if(pts[i]!=strings[i].length()) flag=0;
        }
        //system("pause");
        //cout<<endl;
        if(flag==1) fout<<totalhamle;
        else fout<<"Fegla Won";
        fout<<endl;
    }
    //system("pause");
}
