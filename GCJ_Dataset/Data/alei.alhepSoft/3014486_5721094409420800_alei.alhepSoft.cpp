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

const int mx = 1e3+10;
const int inf = 1e8;
int d[mx];
int a[mx];
int cur[mx];

int main(){
    freopen("ba.in","r",stdin);
    freopen("ba.out","w",stdout);

    int tc,ans=0;
    scanf("%d",&tc);

    for(int tt=1;tt<=tc;tt++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",d+i);
            a[i] = d[i];
        }
        sort(a,a+n);
        ans = inf;
//        cout<<"ok!"<<endl;
        do{
            int center = 0;
            for(int i=1;i<n;i++){
                if(a[i-1]<a[i]){
                    center = i;
                }
                else break;
            }
            bool ok = true;
            for(int i=center+1;i<n && ok;i++){
                if(a[i-1]>a[i]){}
                else ok = false;
            }
            if(ok){
            /*
                cout<<"n="<<n<<" ";for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
                cout<<"center="<<center<<endl;
                cout<<"ok!"<<endl;
*/
                int nswaps = 0;
                for(int i=0;i<n;i++)            
                    cur[i] = d[i];

                for(int i=0;i<n;i++){
                    int idx = -1;
                    for(int j=i;j<n;j++)
                        if(cur[j]==a[i])
                            idx = j;

                    for(int j=idx-1;j>=i;j--){
                        swap(cur[j],cur[j+1]);
                        nswaps++;
                    }
                }
                ans = min(ans,nswaps);

            }
        } while(next_permutation(a,a+n));
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}


