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

const int maxn = 15;

int n;
int nxt[ maxn ];
int x[ maxn ];

bool gen(){
     for(int i=1;i<=n;++i) x[i]=rand()%20+1;//x[i]=rand()%1000 + 1, x[i] *= rand()%1000+1; 
     return true ;
}

int cross(int a, int b, int c, int d) {
    return a*d-b*c;
}

bool ok(){
     for(int i=1;i<n;++i){
           int opt = - 1;
           for(int j=i+1;j<=n;++j){
                bool f=1;
                for(int k=i+1;k<j;++k) if(cross((j-k),x[j]-x[k],(i-k),x[i]-x[k]) <= 0) f=0; 
                for(int k=j+1;k<=n;++k) if(cross((j-k),x[j]-x[k],(i-k),x[i]-x[k]) < 0) f=0; 
                if(f) {
                     opt = j;
                     break; 
                }
           }  
           if(opt == - 1 || opt != nxt[i]) return false;
     }     
     return true;
}

int main(){
    srand( time( NULL));
    freopen("C-small-attempt4.in","r",stdin);
    freopen("C-small-attempt4.out","w",stdout);
    int T, cas = 0;
    cin>>T;
    while(T -- ){
         scanf("%d", &n);
         ++ cas;
         int flg=0;
         for(int i=1;i<n;++i) cin>>nxt[i];
         int ty = 8000000;
         while( gen() && ty > 0) {
                -- ty;
               if( ok()) {
                   flg=1;
                   break;
               } 
         }
         printf("Case #%d:", cas); 
         if(!flg) puts(" Impossible");
         else {
             for(int i=1;i<=n;++i) cout << ' '<< x[i] ;
             puts(""); 
         }
    }
    return 0;
}
