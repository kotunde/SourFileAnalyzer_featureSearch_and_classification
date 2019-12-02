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

int n;
typedef double db;

int W, L;
pair<db, int> R[ maxn ];
pair<db,db> ans[ maxn ];

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T, cas = 0;
    cin>>T;
    while(T -- ){
         scanf("%d", &n);
         ++ cas;
         cin >> W >> L;
         for(int i=0;i<n;++i) cin>>R[i].first, R[i].second=i;
         sort(R,R+n);
         db top = 0.0, left = 0.0, ma = 0.0;
         for(int i=n-1;i>=0;--i){
                 left += R[i].first;
                 if( left > L) {
                     // invalid
                     top += R[i].first + ma;
                     ma = 0.0;
                     left = - R[i].first;
                     ++ i;
                     continue;
                 }
                 int j=R[i].second;
                 ans[j]=make_pair(top, left);
                 ma = max( ma, R[i].first);
                 left += R[i].first;;
         }
         printf("Case #%d:", cas); 
         for(int i=0;i<n;++i) printf(" %.1f %.1f", ans[i].first, ans[i].second);
         puts("");
    }
    return 0;
}
