#include <iostream>

using namespace std;

int main()
{
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
		int n, s, p, res1 = 0, res2 = 0;
		cin >> n >> s >> p;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (3 * p - 2 <= a)
				res1++;
			else if (3 * p - 4 <= a && p >= 2)
				res2++;
		}
		cout << res1 + min(s, res2);
    cout << endl;
  }
  return 0;
}