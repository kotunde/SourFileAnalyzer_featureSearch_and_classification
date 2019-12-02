#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define For(i,a,b) for (int i = a; i < b; i++)

int getInt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	int T = getInt();
	For (t,1,T+1) {
		int n = getInt();
		int c = getInt();
		vector <int> a(n);
		For (i,0,n) {
			a[i] = getInt();
		}
		sort(a.begin(), a.end());
		int res = 0;
		int j = n-1;
		For (i,0,j+1) {
			res++;
			while (c < a[i] + a[j]) {
				if (i == j)
					break;
				res++;
				j--;
			}
			j--;
		}
		printf("Case #%d: %d\n", t, res);
	}
}
