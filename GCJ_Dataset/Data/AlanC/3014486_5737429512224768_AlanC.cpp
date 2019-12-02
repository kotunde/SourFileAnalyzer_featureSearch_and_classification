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
#define N 100005

int TC, s[N], n, C, cnt[1005];

int main(){
	scanf("%d", &TC);
	FOR(tc, 0, TC){
		scanf("%d%d", &n, &C);
		CLR(cnt, 0);
		FOR(i, 0, n){
			scanf("%d", &s[i]);
			cnt[s[i]]++;
		}
		//sort(s, s + n);
		int ret = 0;
		
		for (int i=C;i>=0;i--){
			int x = C - i;
			while (cnt[i] > 0){
				cnt[i]--;
				while (x >= 0 && cnt[x] == 0) x--;
				if (x != -1) cnt[x]--;
				ret++;
			}
		}
		
		printf("Case #%d: %d\n", tc + 1, ret);
		
	}
	return 0;
}

