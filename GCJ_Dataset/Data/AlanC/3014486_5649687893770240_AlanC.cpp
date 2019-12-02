#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

#define FOR(i, s, e) for (int i=(s);i<(e);i++)
#define FOE(i, s, e) for (int i=(s);i<=(e);i++)
#define FOD(i, s, e) for (int i=(s)-1;i>=(e);i--)
#define CLR(x, a) memset(x, a, sizeof(x))
#define LL long long int
using namespace std;

#define N 1005

int n, m, c[N], T[N][26], TC, ret, cnt;
char s[N][N];

int Calc(){
	int R = 0;
	FOR(i, 0, n){
		CLR(T, -1);
		int CC = 0;
		FOR(j, 0, m) if (c[j] == i){
			int z = strlen(s[j]), x = 0;
			FOR(k, 0, z){
				int v = s[j][k] - 'A';
				if (T[x][v] == -1) T[x][v] = ++CC;
				x = T[x][v];
			}
		}
		R += CC + 1;
		//printf("TC[%d] = %d\n", i, CC + 1);
	}
	return R;
}



void DFS(int x){
	if (x == m){
		int b[N], ok = 1;
		FOR(i, 0, n) b[i] = 0;
		FOR(i, 0, m) b[c[i]] = 1;
		FOR(i, 0, n) if (b[i] == 0) ok = 0;
		if (ok){
			//FOR(i, 0, m) printf("%d ", c[i]);
			//printf("\n");
			int t = Calc();
			if (t > ret) ret = t, cnt = 1;
			else if (ret == t) cnt++;
		}
	}
	else 
		FOR(i, 0, n){
			c[x] = i;
			DFS(x + 1);
		}
}

int main(){
	scanf("%d", &TC);
	FOR(tc, 0, TC){
		scanf("%d%d", &m, &n);
		FOR(i, 0, m) scanf("%s", s[i]);
		ret = 0;
		cnt = 0;
		CLR(c, -1);
		DFS(0);
		printf("Case #%d: %d %d\n", tc + 1, ret, cnt);
	}
	return 0;
}

