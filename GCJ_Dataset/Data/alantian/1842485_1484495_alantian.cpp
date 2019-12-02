#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100+ 10;

struct Cycle{
    int r, id;
    int x,y;
    Cycle(int r =0, int id = 0):r(r),id(id),x(0),y(0){}
};
bool operator < (Cycle a, Cycle b ){
    return a.r > b.r;
}
int w,l;
int r[MAXN];
int n;

Cycle c[MAXN];

Cycle ans[MAXN];

void solve( int Case ){
    scanf("%d%d%d",&n,&w,&l);
    for( int i = 0; i < n; i++ )
        scanf("%d",r+i);

    for( int i = 0; i < n; i++ ) 
        c[i] = Cycle(r[i],i);
    c[n] = Cycle(0,n);
    
    sort(c,c+n);

    int x = 0, y = 0, r = 0;

    for( int i = 0; i < n; i++ ){
        c[i].x = x;
        c[i].y = y;
        ans[ c[i].id ]= c[i];
        if ( x == 0 )
            r = y + c[i].r;
        x += c[i].r + c[i+1].r;
        if ( x > w ){
            x = 0;
            y = r + c[i+1].r;
        }
    }
    
    printf("Case #%d:",Case);
    for( int i = 0; i < n; i++ )
        printf(" %d %d",ans[i].x,ans[i].y);
    putchar('\n');

}

int main(){
    int T; scanf("%d",&T);
    for( int Case = 1; Case <= T; Case++ ){
        solve(Case);
    }
}
