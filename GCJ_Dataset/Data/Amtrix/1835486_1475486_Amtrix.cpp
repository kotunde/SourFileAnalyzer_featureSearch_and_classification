#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>
#include <time.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <assert.h>
#include <bitset>
#include <sstream>
#include <fstream>
using namespace std;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define pb push_back

typedef long long ll;

const int maxn = 22;

int n;
int t[maxn];
int p[maxn];

bool cmp(pii a, pii b) {
    return a.f > b.f || (a.f == b.f && a.s < b.s);
}

int main() {
    freopen("Ulaz","r",stdin);
    freopen("Izlaz","w",stdout);

    int tests; scanf("%d",&tests);
    for(int tc = 1; tc <= tests; ++tc) {
        scanf("%d",&n);
        vector<pii> w;
        for (int i = 0; i < n; ++i)
            scanf("%d",t+i);
        for (int i = 0; i < n; ++i) {
            scanf("%d",p+i);
            w.push_back(mk(p[i],i));
        }
        sort(w.begin(), w.end(), cmp);
        printf("Case #%d: ", tc);
        for (int i = 0; i < sz(w); ++i)
            cout<<w[i].s<<" ";cout<<endl;
    }


    return 0;
}
