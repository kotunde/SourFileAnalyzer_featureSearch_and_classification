#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;

const int maxm = 1010;
const int maxn = 10;

string s[maxm];
int m, n;
int best;
int cnt;
int cntbest;
VI v[maxn];

struct node{
	node *c[26];
	node(){
		rep(i,26)
			c[i] = NULL;
	}
	void add(string &s, int id){
		if(id >= s.length())
			return ;
		int x = s[id]-'A';
		if(c[x] == NULL){
			cnt++;
			c[x] = new node;
		}
		c[x]->add(s, id+1);
	}
	~node(){
		rep(i,26)
			if(c[i] != NULL)
				delete c[i];
	}
};

void buildTrie(VI a){
	node *t = new node;
	if(a.size())
		cnt++;
	rep(i,a.size())
		t->add(s[a[i]], 0);
	delete t;
}

void bt(int k){
	if(k == m){
		cnt =0;
		rep(i,n)
			buildTrie(v[i]);
		if(cnt > best){
			best = cnt;
			cntbest = 1;
		}else if (cnt == best)
			cntbest++;
		return ;
	}
	rep(i,n){
		v[i].pb(k);
		bt(k+1);
		v[i].pop_back();
	}
}

int main() {
	int t;
	cin >> t;
	rep(g,t){
		cin >> m >> n;
		rep(i,m)
			cin >> s[i];
		best = 0;
		cntbest = 0;
		bt(0);
		cout << "Case #" << g+1 << ": " << best << " " << cntbest << endl;
	}
	return 0;
}
