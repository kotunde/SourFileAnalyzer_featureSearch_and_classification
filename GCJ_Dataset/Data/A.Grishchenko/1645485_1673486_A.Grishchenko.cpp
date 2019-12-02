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
	for (int tc = 0; tc < T; ++tc) {
		cout<<"Case #" << tc+1 << ": ";
		int A, B;
		cin>>A>>B;
		vector<double> p (A+1, 0);
		p[0] = 1.0;
		for (int i = 1; i <= A; ++i) {
			cin>>p[i];
			p[i] = p[i]*p[i-1];
		}
		double min_m = B+2;
		for (int aa = A; aa >= 0; --aa) {
			double kp = B-A+1 + (A-aa)*2;
			double kp_w = kp+B+1;
			double ex = p[aa]*kp + (1.0 - p[aa])*kp_w;
			if (ex < min_m) min_m = ex;
		}
		printf("%20.10f", min_m);
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