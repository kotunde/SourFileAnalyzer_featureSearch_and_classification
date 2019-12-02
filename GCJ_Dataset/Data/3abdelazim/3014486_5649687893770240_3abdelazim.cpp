#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;

typedef vector <string> vs;
#define For(i,a,b) for (int i = a; i < b; i++)

int cl(int x, int i) {
	int msk = 3;
	msk <<= (2*i);
	msk = -1 ^ msk;
	return x & msk;
}

int g(int x, int i) {
	return ((x >> (2*i)) & 3);
}

bool invalid(int idx, int n, int N) {
	For (i,0,n) {
		if (g(idx, i) >= N)
			return true;
	}
	return false;
}

class Trie {
	public:
	vector <bool> a;
	vector <Trie> t;
	void init() {
		a.assign(26, 0);
		t.resize(26);
	}
	void insert(string s, int idx) {
		if ((int)s.size() == idx)
			return;
		int c = s[idx] - 'A';
		if (a[c] == 0) {
			t[c].init();
			a[c] = 1;
		}
		t[c].insert(s, idx+1);
	}
	int size() {
		int res = 1;
		For(i,0,26) {
			if (a[i]) {
				res += t[i].size();
				res %= 1000000007;
			}
		}
		return res;
	}
};

map <int, map <int, int> > dp;

int CHECK(int j, int i, int n) {
	For (k, 0, n) {
		if (g(i, k) != j) {
			i = cl(i, k);
		}
	}
	return dp[i][j];
}

int SIZE(int j, int i, int n, Trie t) {
	For (k, 0, n) {
		if (g(i, k) != j) {
			i = cl(i, k);
		}
	}
	if (dp[i][j] == 0)
		dp[i][j] = t.size();
	return dp[i][j];
}

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	int T;
	cin >> T;
	For (ts,1,T+1) {
		dp.clear();
		int n, N;
		cin >> n >> N;
		vs a(n);
		For (i,0,n) {
			cin >> a[i];
		}
		int ret1 = -1;
		int ret2 = -1;
		For (i,0,1<<(2*n)) {
			if (invalid(i, n, N))
				continue;
			vector <Trie> t(N);
			For (j,0,N) {
				if (CHECK(j, i, n) == 0)
					t[j].init();
			}
			For (j,0,n) {
				int tar = g(i, j);
				if (CHECK(tar, i, n) == 0)
					t[tar].insert(a[j], 0);
			}
			int res = 0;
			For (j,0,N) {
				int tmp = SIZE(j, i, n, t[j]);
				if (tmp > 1)
					res += tmp;
			}
			if (res > ret1) {
				ret1 = res;
				ret2 = 1;
			}
			else if (res == ret1) {
				ret2++;
			}
		}
		cout << "Case #" << ts << ": " << ret1 << " " << ret2 << endl;
	}
}

