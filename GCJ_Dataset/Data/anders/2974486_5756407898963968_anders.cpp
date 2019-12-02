#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void read(set<int>& vec) {
  int n, tmp;
  cin >> n;
  for (int i=1; i<=4; ++i) {
    for (int j=0; j<4; ++j) {
      cin >> tmp;
      if (i==n) vec.insert(tmp);
    }
  }
}

void solve() {
  set<int> first, second;
  int intersect[4];
  read(first);
  read(second);
  int* out = set_intersection(first.begin(), first.end(), second.begin(), second.end(), intersect);
  if (out-intersect==0)
    cout << "Volunteer cheated!";
  else if(out-intersect==1)
    cout << intersect[0];
  else
    cout << "Bad magician!";
  cout << endl;
}

int main() {
  int c;
  cin >> c;
  for (int i = 1; i<=c; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

