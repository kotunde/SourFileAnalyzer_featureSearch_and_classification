#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void solve() {
  double cost, inc, goal;
  cin >> cost >> inc >> goal;
  double currentTime = 0;
  double currentInc = 2;
  double ans = goal/currentInc; // don't buy anything!
  while (currentTime < ans) {
    currentTime += cost/currentInc;
    currentInc += inc;
    ans = min(ans, currentTime + goal/currentInc);
  }
  cout << setprecision(18) << ans << endl;
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

