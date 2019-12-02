#include<bits/stdc++.h>
using namespace std ;

const int dr[] = {0,-1,-1,-1,0,  1, 1,1};
const int dc[] = {1,-1, 0, 1,-1,-1, 0,1};

int H,W,M;

#define cell(i,j) ((i)*W+(j))

char grid[10][10];
bool vis[10][10];
int rem;

void dfs(int i,int j){
    if (i < 0 || j < 0 || i >= H || j >= W)return ;
    if (grid[i][j] == '*')return ;
    if (vis[i][j])return ;
    vis[i][j] = true;
    rem --;
    bool zero = true;
    for (int dir=0;dir<8;dir++){
        int ii = i+dr[dir],jj = j+dc[dir];
        if (ii < 0 || jj < 0 || ii >= H || jj >= W)continue ;
        zero &= (grid[ii][jj] == '.');
        //printf("%d,%d => %d\n",ii,jj,zero);
    }
    if (zero){
        for (int dir=0;dir<8;dir++){
            int ii = i+dr[dir],jj = j+dc[dir];
            if (ii < 0 || jj < 0 || ii >= H || jj >= W)continue ;
            dfs(ii,jj);
        }
    }
    return ;
    
}

int main(){
    //freopen("sample.in","r",stdin);
    freopen("mines.in","r",stdin);
    freopen("mines.out","w",stdout);
    
    int c,c2;
    int tests;
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++){    
        printf("Case #%d:\n",test);
        scanf("%d%d%d",&H,&W,&M);
        rem = H*W-M;
        for (int mask = 0;mask < (1<<(H*W));mask++){
            if (__builtin_popcount(mask) != M)continue;
            
            for (c=0;c<H;c++)
                for (c2=0;c2<W;c2++)
                    if (mask & (1<<cell(c,c2)))
                        grid[c][c2] = '*';
                    else grid[c][c2] = '.';
            
            for (c=0;c<H;c++)
                for (c2=0;c2<W;c2++){
                    if (grid[c][c2] == '*')continue;
                    memset(vis,0,sizeof(vis));
                    rem = H * W - M;
                    dfs(c,c2);
                    if (rem == 0){
                        grid[c][c2] = 'c';
                        goto barra;
                    }
                }
        }
        barra:
        if (rem == 0){
            for (c=0;c<H;c++){
                for (c2=0;c2<W;c2++)
                    printf("%c",grid[c][c2]);
                printf("\n");
            }
        }
        else printf("Impossible\n");
            
    }
    return 0;
}
