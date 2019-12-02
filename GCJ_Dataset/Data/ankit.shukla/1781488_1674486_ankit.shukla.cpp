#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second
using namespace std;

typedef pair<int,int> pii;
vector<int> adj[1001];
int deg[1001];
bool ans;
void dfs(int n,vector<int>& vis,int pos){
    if(vis[n]==pos){
        ans=true;
        return;
    }
    vis[n]=pos;
    tr(adj[n],it){
        dfs(*it,vis,pos);
    }
}

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T,N,a;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&deg[i]);
            adj[i].clear();
            for(int j=0;j<deg[i];j++){
                scanf("%d",&a);
                adj[i].push_back(a-1);
            }
        }
        
        vector<int> visited(N,-1);
        ans=false;
        for(int i=0;i<N;i++){
            dfs(i,visited,i);
        }
        if(ans)
            printf("Case #%d: Yes\n",I);
        else printf("Case #%d: No\n",I);
    }
    
    return 0;
}

    
