#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
bool chk(int n,int p,bool dir){
    if(dir){
        switch(n%3){
            case 0:
                return n/3 >= p;
            case 1:
                return (n-1)/3 + 1 >=p;
            case 2:
                return (n-2)/3 + 1 >=p;
        }
    }
    else{
        switch(n%3){
            case 0:
                return (n/3 +1 >= p) && (n/3 -1 >=0);
            case 1:
                return ((n-1)/3 + 1 >=p) && ((n-1)/3-1 >=0);
            case 2:
                return ((n-2)/3 + 2 >=p) && ((n-2)/3 >=0);
        }
    }
}
int main(){
   // freopen("B-small-attempt0.IN","r",stdin);
   // freopen("B-small-attempt0.OUT","w",stdout);
    int T,N,S,p,val;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d%d%d",&N,&S,&p);
        int ans=0;
        for(int i=0;i<N;i++){
            scanf("%d",&val);
            if(chk(val,p,true)) ans++;
            else if(S && chk(val,p,false)){
                S--;
                ans++;
            }
        }
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}
        
