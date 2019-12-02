#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int n;
int p[MAXN],l[MAXN];

typedef pair<int,int> PII;
PII o[MAXN];
void solve( int Case ){
    scanf("%d",&n);
    for( int i = 0; i < n; i++ )
        scanf("%d",l+i);
        
    for( int i = 0; i < n; i++ )
        scanf("%d",p+i);

    for( int i = 0; i < n;i++)
        o[i] = PII(-p[i],i);

    sort(o,o+n);
    printf("Case #%d:",Case);
    for( int i = 0; i < n;i++)
        printf(" %d",o[i].second);
    puts("");
}

int main(){
    int T; scanf("%d",&T);
    for( int Case = 1; Case <= T; Case++ ){
        solve(Case);
    }
}
