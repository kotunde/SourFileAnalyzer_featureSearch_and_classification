#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int magic(vector<int> a, vector<int> b, int k) {
	vector<int> r;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(r));
	if (r.size() < 1)
	{
		cout << "Case #" << k << ": Volunteer cheated!" << endl; 
	}
	else if (r.size() > 1)
	{
		cout << "Case #" << k << ": Bad magician!" << endl;
	}
	else 
	{
		cout << "Case #" << k << ": " << r[0] << endl;
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	int T, m, n;
	vector<vector<int> > a(4, vector<int>(4)), b(4, vector<int>(4));
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> m;
		for (int j = 0; j < 4; ++j) 
		{
			for (int k = 0; k < 4; ++k)
			{
				cin >> a[j][k];
			}
		}
		cin >> n;
		for (int j = 0; j < 4; ++j) 
		{
			for (int k = 0; k < 4; ++k)
			{
				cin >> b[j][k];
			}
		}
		magic(a[m-1], b[n-1], i+1);
	}
	return 0;
}
