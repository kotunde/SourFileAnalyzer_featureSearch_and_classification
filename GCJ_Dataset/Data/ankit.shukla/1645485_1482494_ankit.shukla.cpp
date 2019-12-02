#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define F first
#define S second
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii ,int> ppi;
pii Y[1002];
ppi X[1002];
int sol[1002];
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B_small.out","w",stdout);
    int T,N,a,b,req;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d%d",&a,&b);
            X[i]=ppi(pii(a,-b),i);
            Y[i]=pii(b,i);
            sol[i]=0;
        }
        map<int,vector<int> > mp;
        sort(Y,Y+N);
        int req=0,mReq=0,stars=0;
        for(int i=0;i<N;i++){
            req=Y[i].F - stars;
                mReq=max(req,mReq);    
            mp[mReq].push_back(Y[i].S);
            stars+=2;
        }
        //cout<<mReq<<endl;
        sort(X,X+N);
        int pre=0,ans=-1;
        stars=0;
        if(mp.find(pre)!=mp.end()){
            tr(mp[pre],it){
                if(sol[*it]==0) stars+=2;
                else if(sol[*it]==1) stars++;
                sol[*it]=2;
            }
        }
        
        while(mp.find(stars)!=mp.end()){
            int added=0;
            tr(mp[stars],it){
                if(sol[*it]==0) added+=2;
                else if(sol[*it]==1) added++;
                sol[*it]=2;
            }
            if(added==0) break;
            stars+=added;
            added=0;
        }
       // cout<<stars<<endl;       
        for(int i=0;i<N;i++){
            if(stars>=mReq){
                ans=i;
                break;
            }
            if(X[i].F.F-stars >0){
                break;
            }
            if(sol[X[i].S]==0){
                stars++;
                sol[X[i].S]=1;
                while(mp.find(stars)!=mp.end()){
                    int added=0;
                    tr(mp[stars],it){
                        if(sol[*it]==0) added+=2;
                        else if(sol[*it]==1) added++;
                        sol[*it]=2;
                    }
                    if(added==0) break;
                    stars+=added;
                    added=0;
                }
            }
        }
        if(ans==-1 && stars>=mReq) ans=N;
        if(ans!=-1)
            printf("Case #%d: %d\n",I,ans+N);
        else printf("Case #%d: Too Bad\n",I);
    }
    return 0;
}
