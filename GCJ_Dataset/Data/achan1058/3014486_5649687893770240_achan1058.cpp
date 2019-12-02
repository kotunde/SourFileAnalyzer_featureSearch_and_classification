#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef pair<int, int> pii;

#define sz size()
#define pb push_back
#define rep(k,a,b) for (int k = (a); k < (int)(b); k++)
#define rrep(k,a,b) for (int k = (a); k >= (int)(b); k--)
#define irep(k,a) for (auto& k: a)
#define all(c) (c).begin(), (c).end()
#define clr(a) memset((a),0,sizeof(a))
#define mi(r, c, v) vvi(r, vi(c, v))
#define md(r, c, v) vvd(r, vd(c, v))
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 10
#define add(i, j) (i + j) % mod
#define mul(i, j) (i * j) % mod

const double eps = 10e-7;
const int inf = 0x3f3f3f3f;

int numnodes(vs& strs) {
	if (strs.sz == 0)
		return -1;

	int r = 0;
	strs.pb("");
	sort(all(strs));
	rep(i, 1, strs.sz) {
		int same = 0;
		for (; same < strs[i - 1].sz && same < strs[i].sz && strs[i - 1][same] == strs[i][same]; same++);
		r += strs[i].sz - same;
	}

	return r + 1;
}

void D4dumb() {
	int T, N, M;
	cin >> T;

	rep(X, 1, T + 1) {
		cin >> M >> N;

		vs strings(M);
		vi servers(M, 0);
		int biggest = 0, numbig = 0;

		rep(i, 0, M)
			cin >> strings[i];

		while (true) {
			int nn = 0;
			rep(i, 0, N) {
				vs strs;
				rep(j, 0, M) {
					if (servers[j] == i)
						strs.pb(strings[j]);
				}
				nn += numnodes(strs);
			}

			if (nn > biggest) {
				biggest = nn;
				numbig = 1;
			} else if (nn == biggest)
				numbig++;

			servers[M - 1]++;
			rrep(i, M - 1, 1) {
				if (servers[i] == N) {
					servers[i] = 0;
					servers[i - 1]++;
				} else {
					break;
				}
			}
			if (servers[0] == N)
				break;
		}
		cout << "Case #" << X << ": " << biggest << ' ' << numbig << endl;
	}

}

int main() {
	fastio;

	D4dumb();
}