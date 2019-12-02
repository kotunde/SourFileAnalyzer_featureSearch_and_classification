#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 1050;
const int mod = 1000 * 1000 * 1000 + 7;

struct node {       	
	int go[30];
};

int t;
int n, m;
string s[MAXN];
int serv[MAXN];
node nd[MAXN];
bool used[MAXN];
int x, y;
int num = m;

void put(string s, int ind) {
	for (int i = 0; i < (int) s.length(); i++) {
		int cur = s[i] - 'A';
		if (nd[ind].go[cur] == 0) {
			num++;
			memset(nd[num].go, 0, sizeof(nd[num].go));
			nd[ind].go[cur] = num;
			ind = num;
		}
		else
			ind = nd[ind].go[cur];
	}     
}

void go(int pos) {
	if (pos > n) {
		num = m;
		for (int i = 1; i <= m; i++)
			used[i] = false;
		for (int i = 1; i <= m; i++)
			memset(nd[i].go, 0, sizeof(nd[i].go));
		for (int i = 1; i <= n; i++) {
			used[serv[i]] = true;
			put(s[i], serv[i]);	
		}
		for (int i = 1; i <= m; i++)
			if (!used[i])
				num--;
		if (num > x) {
			x = num;
			y = 1;
		}
		else if (num == x) {
			y = (y + 1) % mod;
		}
		return;
	}
	for (int i = 1; i <= m; i++) {
		serv[pos] = i;
		go(pos + 1);
	}
}

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &t);

	for (int tn = 1; tn <= t; tn++) {
		scanf("%d %d\n", &n, &m);
		for (int i = 1; i <= n; i++) {
        	getline(cin, s[i]);			
		}

		x = 0; y = 0;

		go(1);

		printf("Case #%d: %d %d\n", tn, x, y);
	}

	return 0;
}