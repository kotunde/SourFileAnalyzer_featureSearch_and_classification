#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double, int> P;
typedef vector<P> VP;

int main() {
  int t; cin >> t;
  for (int z = 0; z < t; ++z) {
    int n; cin >> n;
	VP v;
	for (int i = 0; i < n; ++i) {
	  P a; cin >> a.first;
	  a.second = 0;
	  v.push_back(a);
	}
	for (int i = 0; i < n; ++i) {
	  P a; cin >> a.first;
	  a.second = 1;
	  v.push_back(a);
	}
	sort(v.rbegin(), v.rend());
	
	int war = n, op = 0;
	for (int i = 0; i < 2 * n; ++i) {
	  if (v[i].second == 1) ++op;
	  else if (op) {
		--op;
		--war;
	  }
	}
	
	int mx = 0, dwar = n, ken = 0;
	while (v[mx].second != 1) ++mx;
	for (int i = 2 * n - 1; i >= 0; --i) {
	  if (v[i].second == 1) ++ken;
	  else if (v[i].second == 0) {
	    if (ken) --ken;
		else {
		  v[mx].second = -2;
		  while (mx < 2 * n and v[mx].second != 1) ++mx;
		  --dwar;
		}
	  }
	}
	cout << "Case #" << z + 1 << ": " << dwar << " " << war << endl;
  }
}