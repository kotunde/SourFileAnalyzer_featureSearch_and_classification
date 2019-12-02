#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 200 + 10, MAXM = 2000000+10;
int m,f,n;
int p[MAXN],s[MAXN];

int h[MAXM];

void solve( int Case ){
    scanf("%d%d%d",&m,&f,&n);
    for( int i = 0; i < n; i++ )
        scanf("%d%d",p+i,s+i);

    memset(h,0,sizeof(h));
    for( int i = 0; i <= m; i++ ){
        if ( i <= f ) continue;
        int rest = i-f;
        for( int j = 0; j < n; j++ ){
            int amount = rest / p[j];
            if ( amount > s[j]+1 )
                amount = s[j]+1;
            h[i] = max( h[i], h[rest-amount*p[j]]+amount );
        }
    }
    int ans = h[m];
    printf("Case #%d: %d\n",Case,ans);
    fprintf(stderr,"Case %d\n",Case);
}

int main(){
    int T; scanf("%d",&T);
    for( int Case = 1; Case <= T; Case++ ){
        solve(Case);
    }
}
