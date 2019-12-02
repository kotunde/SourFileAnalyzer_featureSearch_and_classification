#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> l,p,ind;

bool lesss(int a,int b)
{
    return l[a]*p[b]<l[b]*p[a] || l[a]*p[b]==l[b]*p[a] && a<b;
}

void solve(int t)
{
    printf("Case #%d:",t);
    scanf("%d",&n);
    l.resize(n);
    p.resize(n);
    ind.clear();
    for (int i=0;i<n;++i)
        scanf("%d",&l[i]);
    for (int i=0;i<n;++i)
        scanf("%d",&p[i]);
    for (int i=0;i<n;++i)
        ind.push_back(i);
    sort(ind.begin(),ind.end(),lesss);
    for (int i=0;i<n;++i)
        printf(" %d",ind[i]);
    printf("\n");
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
