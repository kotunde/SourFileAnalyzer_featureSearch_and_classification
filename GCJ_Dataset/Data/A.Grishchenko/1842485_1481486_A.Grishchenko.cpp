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

void solve( )
{
	int T;
	cin>>T;
	for (int tc = 0; tc < T; ++tc) {
		int N, D;
		vector<int> d;
		vector<int> l;

		cin >> N;
		d.resize (N,0);
		l.resize (N,0);
		for (int i = 0; i < N; ++i)
			cin >> d[i] >> l[i];
		cin >> D;

		vector<int> eff_l (N, 0);
		eff_l[0] = d[0];
		int max_dist = 2*d[0];
		int situation = d[0];
		int radius = d[0];

		for (int i = 0; i < N; ++i) {
			if (d[i] > max_dist) break;
			int j = i+1;
			while (j < l.size() && d[i] + eff_l[i] >= d[j]) {
				eff_l[j] = max(eff_l[j], min(d[j] - d[i], l[j]));
				max_dist = max(max_dist, d[j] + eff_l[j]);
				++j;
			}
		}
		cout<<"Case #" << tc+1 << ": ";
		if (max_dist < D) cout << "NO";
		else cout << "YES";
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