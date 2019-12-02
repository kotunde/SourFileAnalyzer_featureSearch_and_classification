#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define REPi(n) for(int i=0;i<(int)(n);++i)
#define REP(i,a,b) for (int i=(int)(a);i<=(int)(b);++i)
typedef long long ll;

string inttostr (int a) {
    string s;
    ostringstream os;
    os << a;
    s = os.str();
    return s;
}

bool possible;
vector<int> maxh;
vector<int> h;

void solve_p (int first, int last) {
	if (first >= last) return;
	if (!possible) return;
	int max_int = maxh[first];
	if (max_int > last) {
		possible = false;
		return;
	}
	for (int i = first + 1; i < max_int; ++i) {
		h[i]--;
	}
	solve_p (first + 1, max_int);
	solve_p (max_int, last);
}

void solve( )
{
	int T;
	cin>>T;
	for (int tc = 0; tc < T; ++tc) {
		int N;
		cin >> N;
		maxh.resize(N-1,0);
		for ( int i = 0; i < N-1; ++i) {
			cin >> maxh[i];
			maxh[i]--;
		}
		h.resize (N, 0);
		for (int i = 0; i < h.size(); ++i)
			h[i] = 0;
		possible = true;
		solve_p (0, N-1);
		cout<<"Case #" << tc+1 << ": ";
		if (possible) {
			int min_h = h[0];
			for (int i = 0; i < N; ++i) {
				if (min_h > h[i]) min_h = h[i];
			}
			for (int i = 0; i < N; ++i) {
				h[i] -= min_h;
				cout << h[i] << " ";
			}
		} else {
			cout << "Impossible";
		}
		cout << endl;
	}
}

void main()
{
	#ifdef _DEBUG
        freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	solve();
}