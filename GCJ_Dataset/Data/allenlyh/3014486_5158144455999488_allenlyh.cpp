#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;

#define PB push_back
#define MP make_pair
#define X first
#define Y second

const int maxn = 1000+10;
const int INF = 200000000;
int w,h;
int n;
struct Tnode {
	int x1,x2,y1,y2;
	void read() {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		y2++;
		x2++;
	}
}reg[maxn];
int col[maxn][maxn*2];
int dis[maxn][maxn*2];
bool mark[maxn][maxn*2];
int ys[maxn*2];
int cnt;
deque<pair<int, int> > que;
pair<int, int> vis;
int x,y;
map<int, int> s;
int tos[maxn*2];
int move[2][8] = {{-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, 1, 0, -1, -1}};

bool chk(int x, int y) {
	if (x < 0 || x >= w || y < 0 || y >= cnt) return 0;
	return 1;
}

void spfa() {
	que.clear();
	memset(mark, 0, sizeof(mark));
	for (int j=0;j<cnt;j++) {
		dis[0][j] = 1-col[0][j];
		que.PB(MP(0,j));
		mark[0][j] = 1;
	}
	for (int i=1;i<w;i++) {
		for (int j=0;j<cnt;j++) {
			dis[i][j] = INF;
		}
	}
	while (!que.empty()) {
		vis = que.front();
		que.pop_front();
		for (int i=0;i<8;i++) {
			x = vis.X + move[0][i];
			y = vis.Y + move[1][i];
			if (!chk(x, y)) continue;
			int cost;
			if (col[x][y] == 1) cost = 0;
			else if (move[1][i] != 0) {
				cost = abs(tos[vis.Y] - tos[y]);
			} else cost = 1;
			if (dis[x][y] > dis[vis.X][vis.Y] + cost) {
				dis[x][y] = dis[vis.X][vis.Y] + cost;
				if (!mark[x][y]) {
					mark[x][y] = 1;
					que.PB(MP(x, y));
				}
			}
		}
	}
}

void work() {
	scanf("%d%d%d", &w, &h, &n);
	for (int i=0;i<n;i++) {
		reg[i].read();
		ys[i*2] = reg[i].y1;
		ys[i*2+1] = reg[i].y2;
	}
	ys[n*2] = 0;
	sort(ys, ys + n * 2 + 1);
	cnt = 0;
	s.clear();
	for (int i=0;i<=n*2;i++) {
		if (i == 0 || ys[i] != ys[i-1]) {
			tos[cnt] = ys[i];
			s[ys[i]] = cnt++;
		}
	}
	for (int i=0;i<n;i++) {
		reg[i].y1 = s[reg[i].y1];
		reg[i].y2 = s[reg[i].y2];
//		printf("%d %d\n", reg[i].y1, reg[i].y2);
	}
	memset(col, 0, sizeof(col));
	for (int k=0;k<n;k++) {
		for (int i=reg[k].x1;i<reg[k].x2;i++) {
			for (int j=reg[k].y1;j<reg[k].y2;j++) {
				col[i][j] = 1;
			}
		}
	}
	/*
	for (int i=0;i<w;i++) {
		for (int j=0;j<cnt;j++) {
			printf("%d ", col[i][j]);
		}
		puts("");
	}
	*/
	spfa();
	int ans = INF;
	for (int i=0;i<cnt;i++) {
		ans = min(ans, dis[w-1][i]);
	}
	printf("%d\n", ans);
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