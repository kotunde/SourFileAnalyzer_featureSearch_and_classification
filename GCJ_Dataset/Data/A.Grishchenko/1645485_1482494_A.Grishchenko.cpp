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

bool comp (pair<int,int>& a, pair<int,int>& b) {
	return a.second > b.second ||
		(a.second == b.second && a.first > b.first);
}
void solve( )
{
	int T;
	cin>>T;
	for (int tc = 0; tc < T; ++tc) {
		cout<<"Case #" << tc+1 << ": ";
		int N;
		cin>>N;
		vector< pair<int,int> > ab(N);
		for (int i = 0; i < N; ++i)
			cin>>ab[i].first>>ab[i].second;
		sort (ab.begin(), ab.end(), comp);
		vector<int> levels (N, 0);

		int moves = 0, stars = 0;
		int stars_to_gain = -1;
		while (stars_to_gain != 0 && stars < N*2) {
			stars_to_gain = 0;
			int level_to_pass = 0;

			int tmp_star;
			for (int i = 0; i < N; ++i) {
				if (stars >= ab[i].second) {
					tmp_star = 2 - levels[i];
				} else
					if (stars >= ab[i].first) {
						tmp_star = 1 - levels[i];
					} else {
						tmp_star = 0;
					}
				if (stars_to_gain == tmp_star && levels[i]==1) {
					stars_to_gain = tmp_star;
					level_to_pass = i;
				}
				if (stars_to_gain < tmp_star) {
					stars_to_gain = tmp_star;
					level_to_pass = i;
					if (stars_to_gain == 2) break;
				}
			}

			levels[level_to_pass] += stars_to_gain;
			stars += stars_to_gain;
			moves++;			
		}

		if (stars != N*2) {
			cout << "Too Bad" << endl;
		} else {
			cout << moves << endl;
		}
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