#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 10000 + 10;

int d[MAXN], l[MAXN];
int D;
int n;

int f[MAXN];

void solve( int Case ){
    scanf("%d",&n);
    for( int i = 0; i < n; i++ )
        scanf("%d%d",d+i,l+i);
    scanf("%d",&D);
    
    memset(f,0,sizeof(f));
    f[0] = d[0]*2;
    
    for( int i = 0; i < n; i++ ){
        for( int j = i + 1; j < n && d[j] <= f[i]; j++ )
            if ( d[j] - d[i] <= l[j] )
                f[j] = max( f[j], d[j] + ( d[j] - d[i] ) );
            else
                f[j] = max( f[j], d[j] + l[j] );
    }

    bool ok = false;
    for( int i = 0; i < n; i++ )
        if ( f[i] >= D ) ok = true;
    printf("Case #%d: %s\n",Case,ok?"YES":"NO");
    //for( int i = 0; i < n; i++ ) printf("%d : f: %d\n",i,f[i]);
}

int main(){
    int T; scanf("%d",&T);
    for( int Case = 1; Case <= T; Case++ ){
        solve(Case);
    }
}
