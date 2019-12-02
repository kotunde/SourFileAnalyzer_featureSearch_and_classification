#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;

#define FILEIN "C.in"
#define FILEOUT "C.out"

int c[105][505];
pair<int, int> par[105][505];
bool get = false;
int step = 0;

int W,H,B;
int dx[] = {-1,0,1};
int dy[] = {0,1,0};

void dfs(int x, int y){
	
	if(y == H-1){
		get = true;
		c[x][y] = INF;
		while(y != 0){
			pair<int,int> cur = par[x][y];
			c[cur.first][cur.second] = INF;
			x = cur.first;
			y = cur.second;
		}
		c[x][y] = INF;
		return;
	}
	if(get == true)
		return;
	c[x][y] = step;
	for(int i = 0; i < 3; ++i){
		int tox = x + dx[i];
		int toy = y + dy[i];
		if(tox >= 0 && tox < W && toy >= 0 && toy < H){
			if(c[tox][toy] != INF && c[tox][toy] != step){
				par[tox][toy] = mp(x,y);
				dfs(tox, toy);
			}
		}
	}
}

bool dfs_wrapper(int low){
	//cout<<low<<" "<<c[low][0]<<endl;
	if(c[low][0] != INF){
		step++;
		dfs(low, 0);
		
		if(get){
			get = false;
			//cout<<low<<endl;
			return true;
		}
	}
	get = false;
	return false;
}


int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
    	memset(c, 0, sizeof c);
    	cin>>W>>H>>B;
    	for(int i = 0; i < W; ++i){
    		for(int j = 0; j < H; ++j){
    			c[i][j] = -1;
    		}
    	}
    	
    	for(int i = 0; i < B; ++i){
    		int lx, ly, rx, ry;
    		cin>>lx>>ly>>rx>>ry;
    		//cout<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<endl;
    		for(int j = lx; j <= rx; ++j){
    			for(int k = ly; k <= ry; ++k){
    				c[j][k] = INF;
    			}
    		}
    	}
    	
    	int res = 0;
    	for(int i = 0; i < W; ++i){
    		if(dfs_wrapper(i))
    			++res;
    	}
        cout << "Case #" << _ << ": ";
        cout<<res<<endl;
    }
    return 0;
}