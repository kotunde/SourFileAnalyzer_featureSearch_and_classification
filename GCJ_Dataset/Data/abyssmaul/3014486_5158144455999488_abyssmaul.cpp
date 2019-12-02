#include <cstdio>
#include <deque>
using namespace std;
#define N 567
#define B 1234
#define mp make_pair

int cst[N][N], dst[N][N]; char s[N][N];
int t, w, h, b, x0[B], y0[B], x1[B], y1[B];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
deque<pair<int,int> > dq;
int main() {
	freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &w, &h, &b);
		for (int i = 0; i < h+5; i++) for (int j = 0; j < w+5; j++) {
			cst[i][j] = 1; s[i][j] = 0;
		}
		for (int i = 0; i < b; i++) {
			scanf("%d %d %d %d", x0+i, y0+i, x1+i, y1+i);
			for (int j = y0[i]; j <= y1[i]; j++) for (int k = x0[i]+1; k <= x1[i]+1; k++) cst[j][k] = 0;
		}
		dq.clear();
		for (int i = 0; i < h; i++) {
			dst[i][0] = 0; dq.push_back(mp(i, 0));
			s[i][0] = 1;
		}
		while (1) {
			int py = dq.front().first, px = dq.front().second; dq.pop_front();
			//if (px > w+1) break;
			//printf("%d %d %d\n", py, px, dst[py][px]);
			if (px == w) {
				printf("Case #%d: %d\n", tc, dst[py][px]); break;
			}
			for (int i = 0; i < 8; i++) {
				int ny = py + dy[i], nx = px + dx[i];
				if (ny < 0 || ny >= h || nx < 0 || s[ny][nx]) continue;
				int nd = dst[py][px] + cst[ny][nx];
				dst[ny][nx] = nd;
				//printf("ADV %d %d %d\n", ny, nx, nd);
				if (cst[ny][nx]) {
					dq.push_back(mp(ny, nx)); s[ny][nx] = 1;
				}
				else {
					dq.push_front(mp(ny, nx)); s[ny][nx] = 1;
				}
			}
		}
	}

	return 0;
}