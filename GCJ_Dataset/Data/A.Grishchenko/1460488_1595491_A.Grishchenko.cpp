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

void solve( )
{
	int T;
	cin>>T;
	for (int tc = 1; tc <= T; ++tc) {
		int N, S, p;
		cin>>N>>S>>p;
		vector<int> res (N, 0);
		for (int i = 0; i < N; ++i)
			cin>>res[i];
		//at least p point if (p-2)*2 + p >= res for surprising: 3p-4>=res
		//at least p point if (p-1)*2 + p >= res for not surprising: 3p-2>=res
		sort(res.begin(), res.end());
		reverse(res.begin(), res.end());
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			if (3*p - 2 <= res[i]) ans++;
			else if (3*p-4 <= res[i] && S>0 && res[i]>=2) { ans++; S--; }
		}
		cout<<"Case #"<<tc<<": "<<ans<<endl;
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