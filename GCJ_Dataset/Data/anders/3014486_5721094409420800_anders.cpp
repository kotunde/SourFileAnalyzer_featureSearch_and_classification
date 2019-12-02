#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

pii vals[1010];

void solve() {
  int n;
  cin >> n;
  for (int i=0; i<n; ++i){
    int tmp;
    cin >> tmp;
    vals[i] = make_pair(tmp, i);
  }
  int ans = 1000000;
  sort(vals, vals+n);
  do {
    int count = 0;
    pii a[11];
    for (int i=0; i<n; ++i) {
      a[i] = vals[i];
      //cout << a[i].first << " ";
    }
    //cout << endl;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<n; ++j) {
	if (a[j].second == i) {
	  while (j != i) {
	    swap(a[j],a[j-1]);
	    --j;
	    ++count;
	  }
	  break;
	}
      }
    }
    //cout << "Count = " << count << endl;
    bool rising = true;
    for (int i=1; i<n; ++i) {
      if (rising) {
	if (vals[i-1].first > vals[i].first) rising = false;
      } else {
	if (vals[i-1].first < vals[i].first){
	  count = 100000;
	  break;
	}
      }
    }
    ans = min(count, ans);
  } while(next_permutation(vals, vals+n));
  cout << ans << endl;
}

int main() {
  int c;
  cin >> c;
  for (int i=1; i<=c; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

