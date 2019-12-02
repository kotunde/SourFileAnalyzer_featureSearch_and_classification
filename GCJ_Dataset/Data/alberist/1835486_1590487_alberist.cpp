#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> parent,rank,parent2,rank2;;
vector<bool> sets,sets2;

void make_set (int v) {
    parent[v] = v;
    rank[v] = 0;
    sets[v] = 0;
    parent2[v] = v;
    rank2[v] = 0;
    sets2[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}
int find_set2(int v) {
    if (v == parent2[v])
        return v;
    return parent2[v] = find_set (parent2[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap (a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];
    }
}
void union_sets2(int a, int b) {
    a = find_set2 (a);
    b = find_set2 (b);
    if (a != b) {
        if (rank2[a] < rank2[b])
            swap (a, b);
        parent2[b] = a;
        if (rank2[a] == rank2[b])
            ++rank2[a];
    }
}
int s,m,s2;

pair<int,int> unpack(int x)
{
    return make_pair(x/s2-2,x%s2-2);
}

int pack(int a,int b)
{
    return (a+2)*s2+b+2;
}

int steps[6][2] = {{-1,-1},{-1,0},{0,1},{1,1},{1,0},{0,-1}};

int pack(pair<int,int> x)
{
    return pack(x.first,x.second);
}

void add(int x,int y)
{
    int key = pack(x,y);
    sets[key] = 1;
    for (int i=0;i<6;++i)
    {
        int key2 = pack(x+steps[i][0],y+steps[i][1]);
        if (sets[key2])
        {
            union_sets(key,key2);
            union_sets2(key,key2);
        }
    }
}

void add2(int x,int y)
{
    int key = pack(x,y);
    sets2[key] = 1;
    for (int i=0;i<6;++i)
    {
        int key2 = pack(x+steps[i][0],y+steps[i][1]);
        if (sets2[key2])
            union_sets2(key,key2);
    }
}

void addx(int x,int y)
{
    add(x,y);
    add2(x,y);
}

void solve(int t)
{
    printf("Case #%d:",t);
    scanf("%d%d",&s,&m);
    s2 = s*2+10;
    int sz = pack(s2,s2);
    parent.resize(sz);
    rank.resize(sz);
    sets.resize(sz);
    parent2.resize(sz);
    rank2.resize(sz);
    sets2.resize(sz);
    for (int i=0;i<sz;++i)
           make_set(i);
    vector<int> corners,forks;
    corners.push_back(pack(1,1));
    corners.push_back(pack(1,s));
    corners.push_back(pack(s,1));
    corners.push_back(pack(s*2-1,s));
    corners.push_back(pack(s,s*2-1));
    corners.push_back(pack(s*2-1,s*2-1));
    if (s==3)
    {
        forks.push_back(pack(2,1));
        forks.push_back(pack(1,2));
        forks.push_back(pack(4,2));
        forks.push_back(pack(2,4));
        forks.push_back(pack(5,4));
        forks.push_back(pack(4,5));
    }
    else
    {
        forks.push_back(pack(2,0));
        forks.push_back(pack(0,2));
        forks.push_back(pack(2,s+2));
        forks.push_back(pack(s+2,2));
        forks.push_back(pack(s*2,2+s));
        forks.push_back(pack(2+s,s*2));
    }

    for (int i=0;i<s-3;++i)
    {
        add2(2+i,0);
        add2(0,2+i);
        add2(2+i,s+2+i);
        add2(s+2+i,2+i);
        add2(s*2,2+s+i);
        add2(2+s+i,s*2);
    }
    bool answered = 0;
    for (int i=0;i<m;++i)
    {
        bool ring=0,bridge=0,fork=0;
        int x,y;
        scanf("%d%d",&x,&y);
        if (!answered)
        for (int j=0;j<5;++j)
            for (int k=j+2;k<6;++k)
                if (find_set(pack(x+steps[j][0],y+steps[j][1])) == find_set(pack(x+steps[k][0],y+steps[k][1])))
                {
                    bool h1=0,h2=0;
                    for (int l=j+1;l<k;++l)
                        if (!sets[pack(x+steps[l][0],y+steps[l][1])])
                            h1 = 1;
                    for (int l=(k+1)%6;l!=j;l=(l+1)%6)
                        if (!sets[pack(x+steps[l][0],y+steps[l][1])])
                            h2 = 1;
                    if (h1 && h2)
                        ring = 1;
                }
        addx(x,y);
        if (!answered)
        for (int j=0;j<5;++j)
            for (int k=j+1;k<6;++k)
                if (find_set(corners[j])==find_set(corners[k]))
                    bridge = 1;
        if (!answered)
        if (s>=3)
        for (int j=0;j<4;++j)
            for (int k=j+1;k<5;++k)
                for (int l=k+1;l<6;++l)
                    if (find_set2(forks[j])==find_set2(forks[k]) && find_set2(forks[j])==find_set2(forks[l]))
                        fork = 1;
        if (ring || bridge || fork)
        {
            if (bridge && fork && ring)
                printf(" bridge-fork-ring");
            else if (bridge && fork)
                printf(" bridge-fork");
            else if (bridge && ring)
                printf(" bridge-ring");
            else if (fork && ring)
                printf(" fork-ring");
            else if (bridge)
                printf(" bridge");
            else if (fork)
                printf(" fork");
            else if (ring)
                printf(" ring");
            printf(" in move %d\n",i+1);
            answered = 1;
        }
    }
    if (!answered)
    printf(" none\n");
}

int main(int argc, char* argv[])
{
    if (argc>1)
        freopen(argv[1],"r",stdin);
    else
        freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for (int t=0;t<T;++t)
        solve(t+1);
    return 0;
}
