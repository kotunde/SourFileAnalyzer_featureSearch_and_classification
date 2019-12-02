#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printAnswer(int x, int ans) {
	cout << "Case #" << x << ": " << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	int A, B, K;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> A >> B >> K;
		int ans = 0;
		if (K >= A && K >= B) {
			ans = A * B;
		} else {
			for (int p = 0; p < A; ++p) {
				for (int q = 0; q < B; ++q) {
					if (K - 1 >= (p & q)) {
						++ans;
					}
				}
			}
		}
		printAnswer(i + 1, ans);
	}
	cout.flush();
	return 0;
}

