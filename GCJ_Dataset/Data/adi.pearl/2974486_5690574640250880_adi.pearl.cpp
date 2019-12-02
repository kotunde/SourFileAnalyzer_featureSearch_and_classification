#include<bits/stdc++.h>
using namespace std;
#define F(i,n) for(int i=0;i<n;++i)
#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);
char g[55][55];
inline bool solve(int r, int c, int m){
    //printf("r: %d c: %d m: %d\n",r,c,m);
    if(m==0){
        F(i,r)F(j,c)g[i][j]='.';
        g[0][0]='c';
        return 1;
    }
    // now m!=0
    if(r==1&&c==1)return 0;
    if(r==2&&c==2){
        if(m!=3)return 0;
        F(i,r)F(j,c)g[i][j]='*';g[0][0]='c';
        return 1;
    }
    int mn=min(r,c);
    if(m>=mn){
        if(mn==r){
            F(i,r)g[i][c-1]='*';
            return solve(r,c-1,m-mn);
        }
        else{
            F(j,c)g[r-1][j]='*';
            return solve(r-1,c,m-mn);
        }
    }
    else if(m<=mn-2){
        for(int i=r-1,cnt=0;i>=0;--i,++cnt)
            if(cnt<m)g[i][c-1]='*';
            else     g[i][c-1]='.';
        F(i,r)F(j,c-1)g[i][j]='.';
        g[0][0]='c';
        return 1;
    }
    //m=mn-1
    else{
        if((r-2)*(c-2)<m)return 0;
        F(i,r)F(j,c)g[i][j]='.';
        int cnt=0;int j=c-1;
        while(cnt<m){
            for(int i=r-1;i>=2 && cnt<m;--i,++cnt)g[i][j]='*';
            j--;
        }
        g[0][0]='c';
        return 1;
    }
}
int main(){
    READ("3.in");
    WRITE("3.out");
    int t,r,c,m;cin>>t;
    for(int caseid=1;caseid<=t;++caseid){
        scanf("%d%d%d",&r,&c,&m);
        printf("Case #%d:\n",caseid);
        if(!solve(r,c,m))printf("Impossible\n");
        else{
            F(i,r){
                F(j,c)printf("%c",g[i][j]);
                printf("\n");
            }
        }
    }
}
