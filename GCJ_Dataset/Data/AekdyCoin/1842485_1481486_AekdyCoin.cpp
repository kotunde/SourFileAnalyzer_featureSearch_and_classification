#include<iostream> 
#include<stdio.h> 
#include<string.h> 
#include<algorithm> 
#include<map> 
#include<queue> 
#include<cmath> 
#include<stack> 
#include<set>
using namespace std; 
 
typedef long long LL; 
typedef double db; 
 
#define pb push_back 
#define mp make_pair 

const int maxn = 10005;

int D[ maxn ], L[ maxn ];
int n;
int f[ maxn ];

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T, cas = 0;
    cin>>T;
    while(T -- ){
         scanf("%d", &n);
         ++ cas;
         memset(f,0,sizeof f);
         for(int i=1;i<=n;++i) cin>>D[i]>>L[i];
         D[0]=L[0]=0;
         cin>>D[n+1];
         L[n+1]=0;
         bool flg=0;
         f[1] = D[1];
         for(int i=1;i<n;++i){
              f[i]=min(f[i],L[i]);   
              for(int j=i+1;j<=n;++j){
                    if(D[i] + f[i] >= D[j] ) f[j]=max(f[j], D[j]-D[i]);  
              }   
         }
         for(int i=1;i<=n;++i) {
                 f[i]=min(f[i],L[i]);   
                 if(D[i]+f[i]>=D[n+1]) flg=1;
         }
         printf("Case #%d: %s\n", cas, flg?"YES":"NO"); 
    }
    return 0;
}
