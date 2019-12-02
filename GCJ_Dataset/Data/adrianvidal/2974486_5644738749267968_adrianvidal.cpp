#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#define vd vector<double>
#define mp make_pair
#define pt pair<int,int>

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
	  vector<double> a,b;
	  for(int i=0; i<n; i++){
	     double d; scanf("%lf",&d);
		 a.push_back(d);
	  }
	  for(int i=0; i<n; i++){
	     double d; scanf("%lf",&d);
		 b.push_back(d);
	  }
	  sort(a.begin(),a.end());
	  sort(b.begin(),b.end());
	  //for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
	  //cout<<endl;
	  //for(int i=0; i<b.size(); i++) cout<<b[i]<<" ";
	  //cout<<endl;
	  //cout<<endl;
	  pt A(0,a.size()-1),B(0,b.size()-1);
	  int ctr=0;
	  for(int i=0; i<n; i++){
	     if (a[A.first]>b[B.first]){
		    ctr++; A.first++; B.first++;
		 }
		 else{
		    A.first++; B.second--;
		 }
	  }
	  int ctr2=0;
	  A=pt(0,a.size()-1);
	  //random_shuffle(a.begin(),a.end());
	  //random_shuffle(a.begin(),a.end());
	  for(int i=0; i<n; i++){
	     int ptr=lower_bound(b.begin(),b.end(),a[A.first])-b.begin();
		 if (ptr==b.size()){
		    b.erase(b.begin()); A.first++; ctr2++;
		 }
		 else{
		    b.erase(b.begin()+ptr); A.first++;
		 }
	  }
	  printf("Case #%d: %d %d\n",cs+1,ctr,ctr2);
   }
}