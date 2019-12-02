#include <iostream>
#include <algorithm>

using namespace std;

double naomi[1010];
double ken[1010];

void deceit(int n) {
  int index = n-1, ans = 0;
  for (int i = n-1; i>=0; --i) {
    if (naomi[index] > ken[i]) {
      --index;
      ++ans;
    }
  }
  cout << ans << " ";
}

void normal(int n) {
  int ans = n;
  for (int i = 0; i<n; ++i) {
    int index = -1;
    for(int j = 0; j<n; ++j) {
      if (index == -1 && ken[j] > -1) index = j;
      if (ken[j] > naomi[i]) {
	index = j;
	--ans;
	break;
      }
    }
    ken[index] = -1;
  }
  cout << ans << endl;
}

void solve() {
  int n;
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> naomi[i];
  }
  for (int i=0; i<n; ++i) {
    cin >> ken[i];
  }
  sort(naomi, naomi+n);
  sort(ken, ken+n);
  deceit(n);
  normal(n);
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

