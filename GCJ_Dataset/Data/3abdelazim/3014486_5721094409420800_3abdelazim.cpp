#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
#define For(i,a,b) for (int i = a; i < b; i++)

int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

int bit(int x, int i) {
	return ((x >> i) & 1);
}

vi get(vi a, int idx, int v) {
	int n = a.size();
	vi res;
	For (i,0,n) {
		if (bit(idx, i) == v) {
			res.push_back(a[i]);
		}
	}
	return res;
}

int count(int idx, int n) {
	int res = 0;
	For (i,0,n) {
		For (j,i+1, n) {
			if (bit(idx, i) == 1 && bit(idx, j) == 0)
				res++;
		}
	}
	return res;
}

int count(vi a, int v) {
	int n = a.size();
	int res = 0;
	For (i,0,n) {
		For (j,i+1, n) {
			if (v) {
				if (a[i] < a[j])
					res++;
			}
			else {
				if (a[i] > a[j])
					res++;
			}
		}
	}
	return res;
}

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	int T = getInt();
	For (t,1,T+1) {
		int n = getInt();
		vi a(n);
		For (i,0,n) {
			a[i] = getInt();
		}
		int finalRes = -1;
		For (i,0,1<<n) {
			vi a0 = get(a, i, 0);
			vi a1 = get(a, i, 1);
			int res = count(i, n);
			res += count(a0, 0);
			res += count(a1, 1);
			if (finalRes == -1 || finalRes > res)
				finalRes = res;
		}
		printf("Case #%d: %d\n", t, finalRes);
	}
}

