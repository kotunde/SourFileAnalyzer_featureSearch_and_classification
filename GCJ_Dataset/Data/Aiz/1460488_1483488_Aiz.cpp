#include <iostream>

using namespace std;

int main()
{
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
		int a, b, res = 0;
		cin >> a >> b;
		for (int n = a; n <= b; n++)
		{
			int p;
			for (p = 10; p < n; p *= 10);
			for (int q = 10; q < n; q *= 10)
			{
				int m = (n % q) * (p / q) + n / q;
				if (n < m && m <= b)
					res++;
			}
		}
		cout << res;
    cout << endl;
  }
  return 0;
}