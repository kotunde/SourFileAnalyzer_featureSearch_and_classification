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

bool comp (pair<int,int>& a, pair<int,int>& b) {
	return (a.first > b.first);
}

void solve( )
{
	int T;
	cin>>T;
	for (int tc = 0; tc < T; ++tc) {
		bool swapped = false;
		int N, W, L;
		cin >> N >> W >> L;
		if (W < L) {
			swap(W,L);
			swapped = true;
		}
		vector< pair<int,int> > r (N);
		for (int i = 0; i < N; ++i) {
			cin >> r[i].first;
			r[i].second = i;
		}
		sort (r.begin(), r.end(), comp);
		vector< pair<int,int> > res (N);

		int pos = 0;
		int round = 0;
		int line = 0;
		res[r[0].second].first = 0; res[r[0].second].second = 0;
		while (1) {
			int sum = 0;
			int firstpos = 0;
			while (pos < r.size() && sum + r[pos].first <= W) {
				res[r[pos].second].second = line;
				if (sum==0) {
					res[r[pos].second].first = 0;
					sum += r[pos].first;
				} else {
					res[r[pos].second].first = sum + r[pos].first;
					sum += r[pos].first*2;
				}
				pos++;
			}
			if (pos == r.size()) break;
			line += r[firstpos].first + r[pos].first;
			if (line > L) break;
		}
		cout<<"Case #" << tc+1 << ": ";
		if (pos != r.size()) {
			cout << "no chanse!" << endl;
		} else {
			for (int i = 0; i < N; ++i) {
				if (!swapped) cout << res[i].first << " " << res[i].second << " ";
				else cout << res[i].second << " " << res[i].first << " ";
			}
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