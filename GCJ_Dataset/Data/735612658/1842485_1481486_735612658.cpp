#include <memory.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 102;

struct R
{
    int p,l;
    bool operator < (const R &other) const
    {
        if(p != other.p)
        {
            return p < other.p;
        }
        return l < other.l;
    }
}rope[MAX];
struct ddd
{
    int id;
    int dis;
    bool operator < (const ddd &other) const
    {
        return dis < other.dis;
    }
};
bool vis[MAX];
priority_queue <ddd> Q;
int n,s;

void read()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&rope[i].p,&rope[i].l);
    }
    sort(rope,rope+n);
    scanf("%d",&s);
    return;
}
int MIN(int a,int b)
{
    return a < b ? a : b;
}

bool bfs()
{
    memset(vis,false,sizeof(vis));
    while(!Q.empty())
    {
        Q.pop();
    }
    ddd cur,tmp;
    if(rope[0].l >= rope[0].p)
    {
        tmp.id = 0;
        tmp.dis = 2*rope[0].p;
        Q.push(tmp);
    }
    while(!Q.empty())
    {
        cur = Q.top();
        Q.pop();
        vis[cur.id] = true;
        if(cur.dis >= s)
        {
            return true;
        }
        for(int i=cur.id+1;i<n;i++)
        {
            if(rope[i].p > cur.dis)
            {
                break;
            }
            else if(rope[i].p + rope[i].l > cur.dis)
            {
                tmp.id = i;
                tmp.dis = rope[i].p + MIN(rope[i].l , rope[i].p - rope[cur.id].p);
                Q.push(tmp);
            }
        }
    }
    return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int  t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        read();
        printf("Case #%d: ",i);
        printf(bfs() ? "YES\n" : "NO\n");
    }
    return 0;
}
