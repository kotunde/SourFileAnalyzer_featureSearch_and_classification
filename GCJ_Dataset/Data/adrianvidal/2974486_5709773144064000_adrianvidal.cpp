#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      double c,f,x; scanf("%lf%lf%lf",&c,&f,&x);
	  double m=0,r=2;
	  double t=0;
	  while(true){
	     // addt'l time w/o new farm
		 double t1=(x-m)/r;
		 // addt'l time w/ new farm
		 double t2;
		 if (c>=m){
		    t2=(c-m)/r + x/(r+f);
		 }
		 else{
		    t2=(x-(m-c))/(r+f);
		 }
		 if (t1<=t2){
		    t+=t1; break;
		 }
		 if (c>=m){
		    t+=(c-m)/r;
			m=0;
			r+=f;
		 }
		 else{
		    m-=c;
			r+=f;
		 }
	  }
	  printf("Case #%d: %.9lf\n",cs+1,t);
   }
}