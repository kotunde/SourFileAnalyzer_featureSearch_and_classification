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
	string train_set = "yeq ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string train_res = "aoz our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	map<char,char> m;
	for (int i = 0; i < train_set.size(); ++i) {
		if (m.find(train_set[i]) == m.end()) m[train_set[i]] = train_res[i];
		else if (m[train_set[i]] != train_res[i] ) cout<<"error!"<<endl;
	}
	m['z'] = 'q';
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	for (int i = 1; i <= n; ++i) {
		getline(cin,s);
		cout << "Case #" << i << ": ";
		for (int j = 0; j < s.length(); ++j)
			cout << m[s[j]];
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