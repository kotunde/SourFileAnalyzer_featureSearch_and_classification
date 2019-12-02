#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<utility>
typedef long long int uli;
using namespace std;

const int mx = 700+10;
int fls[mx];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    int tc,ans=0,n,x,v;
    scanf("%d",&tc);

    for(int tt=1;tt<=tc;tt++){
        scanf("%d %d",&n,&x);
        memset(fls,0,sizeof fls);
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            fls[v]++;
        }
        ans = 0 ;
        for(int i=mx-1;i>0;i--){
            while(fls[i]>0){
                int rem = x-i;
                fls[i]--;
                for(int j=rem;j>=0;j--){
                    if(fls[j]>0){
                        fls[j]--;
                        break;
                    }
                }
                ans++;
            }
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}

