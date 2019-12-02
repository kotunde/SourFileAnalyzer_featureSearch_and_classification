#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, m, n, ans, cans;
char str[8][11];
char *ns[4][11]; int nss[4];
char *sns[4][11];
bool cmp(char *a, char *b) {
	return strcmp(a, b) < 0;
}
void slv(int at) {
	if (at==m) {
		for (int i = 0; i < n; i++) if (!nss[i]) return;
		for (int i = 0; i < n; i++) for (int j = 0; j < nss[i]; j++) sns[i][j] = ns[i][j];
		for (int i = 0; i < n; i++) sort(sns[i], sns[i] + nss[i], cmp);
		int tmp = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < nss[i]; j++) tmp += strlen(sns[i][j]);
		for (int i = 0; i < n; i++) for (int j = 0; j < nss[i]-1; j++) {
			for (int k = 0; sns[i][j][k] && sns[i][j+1][k] && sns[i][j][k] == sns[i][j+1][k]; k++) tmp--;
		}
		if (tmp > ans) {
			ans = tmp; cans = 1;
		}
		else if (tmp == ans) cans++;
	}
	else for (int i = 0; i < n; i++) {
		ns[i][nss[i]++] = str[at];
		slv(at+1);
		nss[i]--;
	}
}
int main() {
	freopen("d.in", "r", stdin); freopen("d.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++) scanf("%s", str+i);
		ans = cans = 0;
		slv(0);
		printf("Case #%d: %d %d\n", tc, ans + n, cans);
	}

	return 0;
}