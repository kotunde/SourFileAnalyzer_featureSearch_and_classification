#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define F first
#define S second
typedef pair<long long int,long long int>pi;
int N,M;
pi A[101],B[101];
long long int items[1000];
long long int ta[1000],tb[1000];
long long int dp[1001][1001];
int c=0;
long long int rec(int i,int j)
{
    if ( i==c || j==c)return 0;
    long long int &ret = dp[i][j];
    if ( ret!=-1)return ret;
    ret = 0;
    ret = max(rec(i+1,j),rec(i,j+1));
    if ( ta[i]==tb[j])
        ret = max(ret,rec(i+1,j+1)+min(items[i],items[j]));
    return ret;
       
}
long long int anrec(int i,int j)
{
    if ( i==N || j==M)return 0;
    long long int& ret = dp[i][j];
       
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d%d",&N,&M);
        int x=0;
        for(int i=0;i<N;i++){
            long long int a,b;
            scanf("%lld%lld",&a,&b);
            if ( x==0)A[x++] = pi(a,b);
            else{
                if ( A[x-1].S == b ){
                    A[x-1].F+=a;   
                }   
                else
                    A[x++] = pi(a,b);
            }
        }
        int y=0;
        for(int i=0;i<M;i++){
            long long int a,b;
            scanf("%lld%lld",&a,&b);
            if ( y==0)B[y++] = pi(a,b);
            else{
                if ( B[y-1].S == b ){
                    B[y-1].F+=a;   
                }   
                else
                    B[y++] = pi(a,b);
            }
        }
        //cout<<x<<" "<<y<<endl;
        long long int ans =0;
        if ( x==3){
            long long int a=0;
            for ( int i=0;i<y;i++){
                if ( A[0].S == B[i].S )
                    a+= max(min(A[0].F-a,B[i].F),0ll);
                long long int b=0;
                for ( int j=i;j<y;j++){
                    if ( A[1].S == B[j].S )
                        b+= max(min(A[1].F-b,B[j].F),0ll);
                    long long int c=0;
                    for ( int k=j;k<y;k++){
                        long long int v=0;
                        if ( A[2].S == B[k].S )
                            c+=max(min(A[2].F-c,B[k].F),0ll);
                        ans = max(ans,a+b+c);
                    }   
                }
            }
        
        }
        if ( x==2){
            long long int a=0;
            for ( int i=0;i<y;i++){
                if ( A[0].S == B[i].S )
                    a+= max(min(A[0].F-a,B[i].F),0ll);
                long long int b=0;
                for ( int j=i;j<y;j++){
                    if ( A[1].S == B[j].S )
                        b+= max(min(A[1].F-b,B[j].F),0ll);
                    ans = max(ans,a+b);
                }   
            }
        }
        if ( x==1){
            long long int a=0;
            for ( int i=0;i<y;i++){
                
                if ( A[0].S == B[i].S)
                    a+= max(min(A[0].F-a,B[i].F),0ll);
                ans = max(ans,a);
            }
        }
        printf("Case #%d: %lld\n",I,ans);
        
        
        //map<long long int,int>mp;
        //long long int ans = 0;
        //memset(dp,-1,sizeof(dp));
        //anrec(0,0);
        
        
        
    }
return 0;
}

/*
3 3
10 1 20 2 25 3
10 2 30 3 20 1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1
3 5
10 1 6 2 10 1
5 1 6 2 10 1 6 2 5 1
*/
