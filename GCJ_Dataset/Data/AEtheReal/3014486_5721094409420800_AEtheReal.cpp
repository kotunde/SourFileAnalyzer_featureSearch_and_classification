#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back
#define INF 2100000000

int n;
int a[111111], b[111111], p[111111];
int f[1111][1111];

int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%d", &n);
	FOR(i,0,n){
		scanf("%d", &a[i]);
	}
	int ans = INF;
	FOR(x,0,1<<n){
		int cans = 0;
		FOR(i,0,n){
			if(x & (1<<i)) b[i]=a[i];
			else b[i]=INF-a[i];
		}
		FOR(i,0,n){
			FOR(j,0,n-1) if(b[j] > b[j+1]){
				swap(b[j],b[j+1]);
				cans++;
			}
		}
		ans = min(ans, cans);
	}
	printf("Case #%d: ", tt);
	printf("%d\n", ans);

}	
return 0;
}


