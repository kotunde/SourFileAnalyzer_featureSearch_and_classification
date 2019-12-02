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
	unsigned char* mp;
	mp = (unsigned char*)malloc(2000000 + 1);
	int tp[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
	for (int tc = 1; tc <= T; ++tc) {
		memset(mp,0,2000000 + 1);
		int a,b;
		cin>>a>>b;
		int csize = 0;
		int tmp = a;
		for (int i = 0; i < 7; ++i) {
			if (tmp > 0) csize = i+1;
			tmp /= 10;
		}
		int ans = 0;
		int ppow = tp[csize];
		if (csize > 1) {
			for (int num = a; num <= b; ++num) {
				if (mp[num] != 0) continue;
				tmp = num;
				int chainsize = 1;
				for (int i = 0; i < csize-1; ++i) {
					if (tmp%10 == 0) {
						tmp = tmp/10 + (tmp%10)*ppow;
						continue;
					} else {
						tmp = tmp/10 + (tmp%10)*ppow;
						if (a <= tmp && tmp <= b && tmp != num && mp[tmp] == 0) {
							mp[tmp] = 1;
							chainsize++;
						}
					}
				}
				if (chainsize > 1) {
					ans += (chainsize-1)*chainsize/2;
					//cout << num << " " << (chainsize-1)*chainsize/2 << endl;
				}
			}
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