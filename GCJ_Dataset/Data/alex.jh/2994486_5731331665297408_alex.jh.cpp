#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,m;
string s[51];
int a[51][51];
bool vis[51];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=1; tt<=t; tt++) {
        cin>>n>>m;
        for (int i=0; i<n; i++) cin>>s[i];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) a[i][j] = 0;
        }
        for (int i=0; i<m; i++) {
            int x,y;
            cin>>x>>y;
            a[x-1][y-1] = 1;
            a[y-1][x-1] = 1;
        }

        vector<int> v;
        for (int i=0; i<n; i++) v.push_back(i);

        string best = "";
        do {
            bool bad = 0;
            for (int i=0; i<n; i++) vis[i] = 0;
            vis[v[0]] = 1;
            for (int i=1; i<n; i++) {
                bool good = 0;
                for (int j=i-1; j>=0; j--) if (vis[v[j]]) {
                    if (a[v[i]][v[j]]) {
                        good = 1;
                        break;
                    }
                    else vis[v[j]] = 0;
                }
                if (!good) {
                    bad = 1;
                    break;
                }
                vis[v[i]] = 1;
            }

            if (bad) continue;

            string str;

            for (int i=0; i<n; i++) str += s[v[i]];

            if (str<best || best=="") best = str;

        } while (next_permutation(v.begin(), v.end()));

        printf("Case #%d: %s\n", tt, best.c_str());
    }

    return 0;

}
