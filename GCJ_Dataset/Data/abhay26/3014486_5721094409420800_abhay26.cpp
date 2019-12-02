/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
map<vector<int>, int> M;
int n;
ll ans;
int l[100],r[100];
void merge(int *a, int b, int mid, int e)
{
    int n1 = mid-b+1;
    int n2 = e - mid;
    for(int i=0;i<n1;i++)
        l[i] = a[b+i];
    for(int j=0;j<n2;j++)
        r[j] = a[mid+1+j];
    int i,j,k;
    for(i=j=0,k=b;k<=e;k++)
    {
        if(j>=n2 || (i<n1 && l[i]<=r[j]))
            a[k] = l[i++];
        else
        {
            ans += n1 - i;
            a[k] = r[j++];
        }
    }
}
void mergesort(int *a, int b, int e)
{
    if(b<e)
    {
        int mid = (b+e)/2;
        mergesort(a,b,mid);
        mergesort(a,mid+1,e);
        merge(a,b,mid,e);
    }
}
vector<int> Glob;
vector<int> Q[15];
int temp[15];
int GG[15],P[15];
int ret;
void dist(vector<int> V, vector<int> G)
{
    ans = 0;
    FOR(i,15)
    {
        Q[i].clear();
    }
    for ( int i = 0; i < n; ++i )
        Q[ G[i] ].push_back(i);

memset(temp,0,sizeof temp);
for ( int i = 0; i < n; ++i )
    P[i+1] = 1 + Q[ V[i] ][ temp[ V[i] ]++ ];
    for(int i=1;i<=n;i++)
        GG[i-1] = P[i];
    mergesort(GG,0,n-1);
    ret = min(ret,(int)ans);
}
int done[15];
void calc(vector<int> V, int flag)
{
    if(V.size() == n)
    {
        if(V == Glob)
            return;
        dist(V,Glob);
       // FOR(i,n)
       // {
       //     cout << V[i] << " ";
//
       // }cout << ans << endl;
        return;
    }
    int last = V[V.size()-1];
    for(int i=1;i<=n;i++)
        done[i] = 0;
    FOR(i,V.size())
    {
        done[V[i]] = 1;
    }
    if(!flag)
    {
        for(int i=last+1;i<=n;i++)
        {
            if(done[i])
                continue;
            vector<int> W = V;
            W.pb(i);
            calc(W,0);
        }
        for(int i=1;i<last;i++)
        {
            if(done[i])
                continue;
            vector<int> W = V;
            W.pb(i);
            calc(W,1);
        }
    }
    else
    {
         for(int i=1;i<last;i++)
        {
            if(done[i])
                continue;
            vector<int> W = V;
            W.pb(i);
            calc(W,1);
        }
    }
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(z,t)
    {
       // int n;
       ret = 1000000000;
       ans = 0;
        M.clear();
        scanf("%d",&n);
        vector<int> V;
        FOR(i,n)
        {
            int x;
            scanf("%d",&x);
            V.pb(x);
        }
        vector<int> G = V;
        sort(G.begin(),G.end());
        map<int, int> QQ;
        FOR(i,n)
        {
            QQ[G[i]] = i+1;
        }
        FOR(i,n)
        {
            V[i] = QQ[V[i]];
        }
        int fl = 0;
        FOR(i,n-1)
        {
            if(V[i+1] < V[i] && fl == 0)
                fl = 1;
            else if(V[i+1] > V[i] && fl == 1)
            {
                fl = 2;
                break;
            }
        }
       // cout << fl << endl;
        if(fl < 2)
        {
            printf("Case #%d: %d\n",z+1,0);
            continue;
        }
        Glob = V;
        for(int i=1;i<=n;i++)
        {
            vector<int> W;
            W.pb(i);
            calc(W,0);
        }
        printf("Case #%d: %d\n",z+1,ret);
    }
return 0;
}
