#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; ++test) {
		int R, C, mines;
		scanf("%d%d%d", &R, &C, &mines);
		vector<vector<char>> ans(max(R, C), vector<char>(max(R, C)));
		bool flip = false;
		if (R < C) {
			swap(R, C);
			flip = true;
		}
		int empty = R * C - mines;
		bool ok = false;
		for (int a = 2; a <= R; ++a) {
			int b = empty / a;
			int extra = empty % a;
			// printf("a: %d, b: %d, extra: %d\n", a, b, extra);
			if (b + (extra != 0) > C || b <= 1)
				continue;
			if (a != R && a - extra <= 2)
				continue;
			ok = true;
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j) {
					ans[i][j] = ((i < a) && (j < b + (i < extra))) ? '.' : '*';
				}
			if (ans[0][0] != '*')
				ans[0][0] = 'c';
			break;
		}
		if (!ok && C == 1) {
			// printf("corner!\n");
			ok = true;
			ans[0][0] = 'c';
			int i = R - 1;
			for (int k = 0; k < mines; ++k, --i)
				ans[i][0] = '*';
			for (; i > 0; --i)
				ans[i][0] = '.';
		}

		if (!ok && empty == 1) {
			ok = true;
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
					ans[i][j] = '*';
			ans[0][0] = 'c';
		}
		printf("Case #%d:\n", test + 1);
		if (ok) {
			if (!flip) {
				for (int i = 0; i < R; ++i) {
					for (int j = 0; j < C; ++j)
						printf("%c", ans[i][j]);
					printf("\n");
				}
			} else {
				for (int i = 0; i < C; ++i) {
					for (int j = 0; j < R; ++j)
						printf("%c", ans[j][i]);
					printf("\n");
				}
			}
		} else
			printf("Impossible\n");
	}
	return 0;
}