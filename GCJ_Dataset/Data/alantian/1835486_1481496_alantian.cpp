#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 36, MAXL = 5000 + 10;

int tr(char ch, int a){
    if (a){
        if(ch=='o')return 0;
        if(ch=='i')return 1;
        if(ch=='e')return 3;
        if(ch=='a')return 4;
        if(ch=='s')return 5;
        if(ch=='t')return 7;
        if(ch=='b')return 8;
        if(ch=='g')return 9;
    }
    return ch-'a'+10;
}

char buf[MAXL];
int k;
int n;

int ng[80][80];
int din[80],dout[80];

int go(){
    memset(din,0,sizeof(din));
    memset(dout,0,sizeof(dout));
    for( int i = 0; i < 80; i++ )
        for( int j = 0; j < 80; j++ )
            if(ng[i][j]){
                din[j]++;
                dout[i]++;
            }
    int ans=0;
    for( int i = 0; i < 80; i++ ){
        if (din[i]>dout[i])ans+=din[i]-dout[i];
    }
    if(ans==0)ans++;
    for (int i=0;i<80;i++)
        for(int j=0;j<80;j++)if(ng[i][j]){
            ans++;
        }
    return ans;
}

void solve( int Case ){
    scanf("%d",&k);
    scanf("%s",buf);
    int l = strlen(buf);

    memset(ng,false,sizeof(ng));
    for( int i = 1; i < l; i++ )
        for (int a = 0; a < 2; a++ )
            for ( int b = 0 ; b < 2; b++ ){
                int x = tr(buf[i-1],a);
                int y = tr(buf[i],b);
        //        printf("%d %d\n",x,y);
                ng[x][y] = true;
            }
    int ans = go();
    printf("Case #%d: %d\n",Case,ans);
}

int main(){
    int T; scanf("%d",&T);
    for( int Case = 1; Case <= T; Case++ ){
        solve(Case);
    }
}
