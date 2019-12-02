#include <iostream>
#include <vector>

using namespace std;

int deceit(vector<double> a, vector<double> b, int n) {
	double t, min, max;
	if (n == 1) {
		return a[0]>b[0]?1:0;
	}
	else {
		t = a[0];
		min = b[0];
		max = b[n-1];
		if (t > max)
			return n;
		else if (t < min) {
			a.erase(a.begin());
			b.pop_back();
			return deceit(a, b, n-1);
		}
		else {
			a.erase(a.begin());
			int lose, win;
			b.pop_back();
			lose = deceit(a, b, n-1);
			b.push_back(max);
			b.erase(b.begin());
			win = deceit(a, b, n-1)+1;
			return win>lose?win:lose;
		}
	}
}

int war(vector<double> a, vector<double> b, int n) {
	if (n == 1) {
		return a[0]>b[0]?1:0;
	}
	else {
		double t = a[0], r = 1;
		for(int i = 0; i < n; i++) {
			if (b[i] > t) {
				r = 0;
				b.erase(b.begin()+i);
				break;
			}
		}
		if (b.size() == n)
			b.erase(b.begin());
		a.erase(a.begin());
		return war(a, b, n-1)+r;
	}
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<double> a(N), b(N);
		for (int j = 0; j < N; ++j)
		{
			cin >> a[j];
		}
		sort(a.begin(), a.end());
		for (int j = 0; j < N; ++j)
		{
			cin >> b[j];
		}
		sort(b.begin(), b.end());
		cout << "Case #" << i+1 << ": " << deceit(a, b, N) << " " << war(a, b, N) << endl;
	}
	return 0;
}