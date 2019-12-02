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
#define INF 1000000000

int n,m;
char s[1111][1111];
int a[1111];
int ans, ansn;

void exh(int i){
	if(i == m){
		set<string> se[10];
		int cans = 0;
		FOR(k,0,m){
			char tmp = 0;
			for(int t=0; ; t++){
				swap(s[k][t], tmp);
				string c(s[k]);
				if(se[a[k]].find(c) == se[a[k]].end()){
					se[a[k]].insert(c);
					cans ++;
				}
				swap(s[k][t], tmp);
				if(s[k][t] == 0) break;
			}
		}
		if(cans > ans){
			ans = cans;
			ansn = 1;
		}else if(cans == ans){
			ansn++;
		}
		return;
	}
	FOR(j,0,n){
		a[i]=j;
		exh(i+1);
	}
}

int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%d%d", &m, &n);
	FOR(i,0,m) scanf("%s", s[i]);
	
	ans = -1; ansn = 0;
	exh(0);
	
	printf("Case #%d: ", tt);
	printf("%d %d\n", ans, ansn);

}	
return 0;
}


