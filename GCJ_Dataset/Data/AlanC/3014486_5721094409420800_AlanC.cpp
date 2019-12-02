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

#define N 1005
using namespace std;

int a[N], b[N], c[N], t[N], TC, T[N], n, cnt, pos;
int pre[N], suf[N];

int query(int x){
	int Q = 0;
	for (int i=x;i>=1;i-=i&-i) Q += T[i];
	return Q;
}

void update(int x){
	for (int i=x;i<=n;i+=i&-i) T[i]++;
}

void Calc(int p[]){
	p[0] = 0;
	FOR(i, 0, n){
		p[i + 1] = p[i];
		FOR(j, 0, i) if (a[i] < a[j]) p[i + 1]++;
	}
}

int main(){
	scanf("%d", &TC);
	FOR(tc, 0, TC){
		scanf("%d", &n);
		FOR(i, 0, n){
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + n);
		FOR(i, 0, n)
			a[i] = lower_bound(b, b + n, a[i]) - b + 1;
		
		pre[0] = suf[0] = 0;
		Calc(pre);
		
		reverse(a, a + n);
		Calc(suf);
		
		int ret = n * n * 4;
		
		FOE(i, 0, n){
			ret = min(ret, pre[i] + suf[n - i]);
			//printf("pos = %d, pre = %d, suf = %d\n", i, pre[i], suf[n - i]);
		}
		
		printf("Case #%d: %d\n", tc + 1, ret);
		
		
	}
	return 0;
}

