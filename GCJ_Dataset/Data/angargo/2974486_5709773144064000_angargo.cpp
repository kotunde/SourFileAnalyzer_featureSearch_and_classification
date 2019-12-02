#include <iostream>
#include <cmath>
using namespace std;

typedef double ld;

int main() {
  cout.setf(ios::fixed);
  cout.precision(7);
  int t; cin >> t;
  for (int z = 0; z < t; ++z) {
    ld c, f, x; cin >> c >> f >> x;
	int k = max(0, int(ceil(((x - c) * f - 2 * c) / (c * f)) + 1e-4));
	ld time = x / (2. + k * f);
	for (int i = 0; i < k; ++i) time += c / (2. + i * f);
	cout << "Case #" << z + 1 << ": " << time << endl;
  }
}