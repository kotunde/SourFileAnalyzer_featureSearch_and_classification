#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<bitset>
using namespace std;

int main(){
   int T; scanf("%d",&T);
   bitset<16> vis;
   for(int cs=0; cs<T; cs++){
      int a; scanf("%d",&a); a--;
	  vis.set();
	  for(int i=0; i<4; i++){
	     int x[4];
		 for(int j=0; j<4; j++){
		    scanf("%d",&x[j]); x[j]--;
			if (i!=a) vis[x[j]]=0;
		 }
	  }
	  scanf("%d",&a); a--;
	  for(int i=0; i<4; i++){
	     int x[4];
		 for(int j=0; j<4; j++){
		    scanf("%d",&x[j]); x[j]--;
			if (i!=a) vis[x[j]]=0;
		 }
	  }
	  printf("Case #%d: ",cs+1);
	  if (vis.count()==0) puts("Volunteer cheated!");
	  else if (vis.count()>1) puts("Bad magician!");
	  else{
	     for(int i=0; i<16; i++){
		    if (vis[i]){
			   printf("%d\n",i+1); break;
			}
		 }
	  }
   }
}