#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef vector<PP> VPP;
typedef vector<int> VI;

int main() {
  int t; cin >> t;
  for (int z = 0; z < t; ++z) {
    int f, s;
	VI prim(16), sec(16);
	cin >> f; --f;
	for (int i = 0; i < 4; ++i) {
	  for (int j = 0; j < 4; ++j) {
	    int c; cin >> c; --c;
		prim[c] = i;
	  }
	}
	cin >> s; --s;
	for (int i = 0; i < 4; ++i) {
	  for (int j = 0; j < 4; ++j) {
	    int c; cin >> c; --c;
		sec[c] = i;
	  }
	}
	
	int sol = -1;
	for (int i = 0; i < 16; ++i) {
	  if (prim[i] == f and sec[i] == s) {
	    if (sol == -1) sol = i;
		else sol = -2;
	  }
	}
	
	cout << "Case #" << z + 1 << ": ";
	if (sol == -1) cout << "Volunteer cheated!" << endl;
	else if (sol == -2) cout << "Bad magician!" << endl;
	else cout << sol + 1 << endl;
  }
}