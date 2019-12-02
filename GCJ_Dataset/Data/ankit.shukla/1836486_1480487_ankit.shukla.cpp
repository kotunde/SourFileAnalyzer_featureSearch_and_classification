#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define tr(container,it) for(typeof(container.begin()) i=container.begin();i!=container.end();it++)
#define F first
#define S second

using namespace std;
typedef pair<int, int> pii;

bool sol[1000];
int X[1000];
int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T,N;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d",&N);
        int tot=0;
        for(int i=0;i<N;i++){
            scanf("%d",&X[i]);
            tot+=X[i];
            sol[i]=false;
        }
        
        int fTot=2*tot,fN=N;
        double req;
        for(int ii=0;ii<=N;ii++){
//            cout<<"here:"<<endl;
            if(fN==1) break;
            req=(fTot)/(double)fN;
            for(int i=0;i<N;i++){
                if(!sol[i] && req<=X[i]){
                    sol[i]=true;
                    fTot-=X[i];
                    fN--;
                }
            }
        }
        printf("Case #%d: ",I);
        for(int i=0;i<N;i++){
            if(!sol[i])
                printf("%.8lf ",(100.0*(req-X[i]))/(double)tot);
            else printf("0.00000000 ");
        }
        printf("\n");
    }
    
    return 0;
}
