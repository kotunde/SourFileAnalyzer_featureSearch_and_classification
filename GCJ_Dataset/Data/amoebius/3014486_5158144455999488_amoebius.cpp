#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;
#define fo(i,n) for(int i=0, _n=(n); i < _n; ++i)
#define range(i,a,b) for(int i=(a), _n=(b); i < _n; ++i)

const int MAX_R = 510, MAX_C = 110;
int R, C, B;
bool board[MAX_R][MAX_C];
bool seen[MAX_R][MAX_C];
typedef pair<int, int> pr;
typedef pair<int, pr> st;

const int NDIR = 8, DR[] = {-1, 1, 0, 0, 1, 1, -1, -1}, DC[] = {0, 0, -1, 1, 1, -1, 1, -1};

#define _d first
#define _p second
#define _r first
#define _c second

inline bool legit(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

int main() {
	int T;
	cin >> T;
	range(testCase, 1, T+1) {
		
		cin >> C >> R >> B;
		fo(r,R) fo(c,C) board[r][c] = seen[r][c] = false;
		fo(i, B) {
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			range(r, y0, y1+1) range(c, x0, x1+1) board[r][c] = true;
		}
		deque<st> q;
		fo(r,R) q.push_back(st(0, pr(r, -1)));

		int bestD;

		while(q.size()) {
			int d = q.front()._d, r = q.front()._p._r, c = q.front()._p._c; q.pop_front();
			if(c == C-1) {
				bestD = d;
				break;
			}
			if(legit(r,c)) {
				if(seen[r][c]) continue;
				seen[r][c] = true;
			}
			fo(i,NDIR) {
				int nr = r + DR[i], nc = c + DC[i];
				if(legit(nr, nc) && !seen[nr][nc]) {
					if(board[nr][nc]) {
						q.push_front(st(d, pr(nr, nc)));
					} else {
						q.push_back(st(d+1, pr(nr, nc)));
					}
				}
			}
		}

		cout << "Case #" << testCase << ": " << bestD << endl;
	}
}