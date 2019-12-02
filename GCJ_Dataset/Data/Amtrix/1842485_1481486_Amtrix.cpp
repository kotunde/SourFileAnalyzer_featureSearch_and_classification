#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const int maxn = 10000;

int n;
int d[maxn];
int l[maxn];
int mx[maxn];

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d",&d[i],&l[i]);
        }
        int love; scanf("%d",&love);

        d[n] = love;
        l[n] = 1000000000;
        memset(mx, -1, sizeof(mx));
        mx[0] = d[0];

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i && mx[i] == -1; ++j) {
                if(mx[j] == -1) continue;
                int dst = d[i] - d[j];
                if(mx[j] >= dst) mx[i] = min(dst, l[i]);
            }
        }

        printf("Case #%d:", t);
        if(mx[n] != -1) printf(" YES\n");
        else printf(" NO\n");
    }
    return 0;
}
