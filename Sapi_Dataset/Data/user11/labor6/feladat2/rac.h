#ifndef RAC_H_INCLUDED
#define RAC_H_INCLUDED
using namespace std;

class rational{
int n,m;
public:
int getM() const{return m;}
int getN() const{return m;}
rational (int m=0,int n=1):m(m),n(n==0?1:n){}
friend ostream& operator<<(ostream & os,const rational & r);

};
ostream& operator <<(ostream& os, const rational & r){
os<<r.m<<"/"<<r.n;
return os;}

#endif // RAC_H_INCLUDED
