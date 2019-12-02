#include<cstdio>
#include<set>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

#define mp make_pair
#define pb push_back
typedef double db;
typedef long long LL;

const int maxn = 55555;
int a[ maxn ];
const db EPS = 1e-8;
db L[ maxn], P[ maxn ];

bool cmp(int a, int b) {
     db va, vb;
     va = L[a] * P[b];
     vb = L[b] * P[a];
     if(fabs(va-vb)<EPS) return a < b;
     return va < vb;
}

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,n;
    int cas = 0;
    cin>>T;
    while(T--){
       ++ cas;
       cin>>n;
       for(int i=0;i<n;++i) a[i]=i;
       for(int i=0;i<n;++i) cin>>L[i];
       for(int i=0;i<n;++i) cin>>P[i];
       printf("Case #%d:", cas);
       sort(a,a+n,cmp);
       for(int i=0;i<n;++i) cout << ' '<< a[i];
       cout << endl;
    }
  	return 0;
}
