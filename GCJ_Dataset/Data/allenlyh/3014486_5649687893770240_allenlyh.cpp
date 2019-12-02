#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

const int maxn = 1000+10;
int n, m;
string st[maxn];
int bt[maxn];
int ans, tot;
set<string> s;
string tmp;

void check() {
	int ta=0;
	for (int i=0;i<m;i++) {
		s.clear();
		for (int j=0;j<n;j++) {
			if (bt[j] == i) {
				tmp = "";
				s.insert(tmp);
				for (int k=0;k<st[j].length();k++) {
					tmp = tmp + st[j][k];
					s.insert(tmp);
				}
			}
		}
		if (s.size() == 1) return;
		ta += s.size();
	}
	if (ta > ans) {
		ans = ta;
		tot = 1;
	} else if (ta == ans) {
		tot++;
	}
}

void dfs(int p) {
	if (p == n) {
		check();
		return;
	}
	for (int i=0;i<m;i++) {
		bt[p] = i;
		dfs(p+1);
	}
}

void work() {
	ans = -1, tot = 0;
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		cin>>st[i];
	}
	dfs(0);
	printf("%d %d\n", ans, tot);
}

int main() {
	int T;
	int cas = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}