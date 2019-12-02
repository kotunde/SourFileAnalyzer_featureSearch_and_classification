#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;

int n, m;
vector<string> arr;
string res;
set<vector<int> > s;

void getans(vector<int> pr){
	string buf;
	for(int i=0; i<pr.size(); i++){
		int j = pr[i];
		buf += arr[j];
	}
	res = min(res, buf);
}

void dfs(int st, int v, vector<vector<int> > gr, vector<int> path, vector<pair<int, int> > edg, vector<char> us){
	s.insert(path);
	if(path.size() == n){
		getans(path);
		return;
	}
	for(int i=0; i<n; i++){
		if(gr[v][i] == 1){
			bool ch = false;
			if(us[i]){
				int j = edg.size()-1;
				if(i == edg[j].first && v == edg[j].second){
					ch = true;
				}
				if(!ch)
					continue;
			}

			bool fl = true;
			for(int j=0; j<path.size(); j++){
				if(i == path[j]){
					fl = false;
					break;
				}
			}
			if(fl)
				path.push_back(i);
			
			if(s.find(path) != s.end() && fl){
				path.pop_back();
				continue;
			}			

			edg.push_back(make_pair(v, i));
			gr[v][i] = 0;
			
			if(!ch)
				us[i] = 1;
			

			dfs(st, i, gr, path, edg, us);

			edg.pop_back();

			if(fl)
				path.pop_back();
			if(!ch)
				us[i] = 0;
			gr[v][i] = 1;
		}
		
	}
}

int main(){	
	//freopen("input.txt", "r", stdin);
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin>>test;
	for(int t=0; t<test; t++){
		cerr<<t<<endl;
		vector<vector<int> > g;
		s.clear();
		g.clear();
		arr.clear();
		res.clear();
		cin>>n>>m;
		g.assign(n, vector<int> (n, 0));
		arr.resize(n);
		for(int i=0; i<n; i++){
			res += "99999";
		}

		for(int i=0; i<n; i++)
			cin>>arr[i];
		for(int i=0; i<m; i++){
			int a, b;
			cin>>a>>b;
			g[a-1][b-1] = 1;
			g[b-1][a-1] = 1;
		}

		vector<pair<int, int> > edg;
		vector<char> us(n, false);
		vector<int> path;
		for(int i=0; i<n; i++){
			s.clear();
			path.push_back(i);
			dfs(i, i, g, path, edg, us);
			path.pop_back();
		}

		cout<<"Case #"<<t+1<<": ";
		cout<<res;
		cout<<"\n";
	}

	return 0;
}