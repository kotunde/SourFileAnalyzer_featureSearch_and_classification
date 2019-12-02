#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
int a[2000];
int b[2000];

/*
int bubble(int x, int y){
   if (x>y) return 0;
   int ctr=0;
   for(int i=x; i<=y; i++){
      int loc=i;
	  while(loc+1<=y && a[loc]>a[loc+1]){
	     swap(a[loc],a[loc+1]);
		 ctr++;
	  }
   }
   return ctr;
}

int bubble2(int x, int y){
   if (x>y) return 0;
   int ctr=0;
   for(int i=x; i<=y; i++){
      int loc=i;
	  while(loc+1<=y && a[loc]<a[loc+1]){
	     swap(a[loc],a[loc+1]);
		 ctr++;
	  }
   }
   return ctr;
}
*/

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
	  int maxval=0,ind=-1;
	  for(int i=0; i<n; i++){
	     scanf("%d",&a[i]); b[i]=a[i];
		 if (a[i]>maxval){
		    maxval=a[i];
			ind=i;
		 }
	  }
	  // ind - location of largest element
	  /*
	  int ans=bubble(0,ind-1)+bubble2(ind+1,n-1);
	  
	  printf("Case #%d: %d\n",cs+1,ans);*/
	  sort(b,b+n);
	  int aa[n];
	  int minval=INT_MAX;
	  for(int i=0; i<n; i++) aa[i]=a[i];
	  do{
	     int loc=-1;
		 for(int i=0; i<n; i++){
		    if (b[i]==maxval){
			   loc=i; break;
			}
		 }
		 bool valid=true;
		 for(int i=0; i+1<=loc; i++){
		    if (b[i]>b[i+1]){
			   valid=false; break;
			}
		 }
		 if (!valid) continue;
		 for(int i=n-1; i-1>=loc; i--){
		    if (b[i]>b[i-1]){
			   valid=false; break;
			}
		 }
		 if (!valid) continue;
		 
	     map<int,int> K;
		 for(int i=0; i<n; i++) K[b[i]]=i;
		 
		 
		 int ctr=0;
		 for(int i=0; i<n; i++){
		    for(int j=i+1; j<n; j++){
			   if (K[aa[i]]>K[aa[j]]) ctr++;
			}
		 }
		 minval=min(ctr,minval);
	  }while(next_permutation(b,b+n));
	  
	  printf("Case #%d: %d\n",cs+1,minval);
   }
}