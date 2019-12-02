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
string S[10];
int m,n;
int max1,cnt;
void calc(vector<vector<string> > V, int p)
{
    if(p == m)
    {
        int cur = 0;
        FOR(i,n)
        {
            vector<string> G = V[i];
            if(G.size() == 0)
                return;
            set<string> S;
            FOR(j,G.size())
            {
                string str = G[j];
                FOR(k,str.length())
                {
                    S.insert(str.substr(0,k+1));
                }
            }
            cur += S.size() + 1;
        }
        if(cur > max1)
        {
            max1 = cur;
            cnt = 1;
        }
        else if(cur == max1)
        {
            cnt++;
        }
        return;
    }
    FOR(i,n)
    {
        vector<vector<string> > G = V;
        G[i].pb(S[p]);
        calc(G,p+1);
    }
}
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
   // freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(z,t)
    {
        max1 = 0;
        cnt = 0;
        scanf("%d %d",&m,&n);
        FOR(i,m)
        {
            cin >> S[i];
        }
        for(int i=0;i<n;i++)
        {
            vector<vector<string> > V;
            vector<string> G;
            FOR(j,n)
            V.pb(G);
            V[i].pb(S[0]);
            calc(V,1);
        }
        printf("Case #%d: %d %d\n",z+1,max1,cnt);
    }
return 0;
}
