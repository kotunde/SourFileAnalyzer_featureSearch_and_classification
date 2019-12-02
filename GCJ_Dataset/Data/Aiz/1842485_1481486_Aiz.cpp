#include <iostream>

using namespace std;

int d[10005], l[10005];
int par[10005];

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
		int n, D;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i] >> l[i];
			par[i] = i ==1 ? 0 : -1;
		}
		cin >> d[n+1];
		par[n+1] = -1;
		for (int i = 1; i <= n; i++)
		{
			if (par[i] < 0) continue;
			int rb = d[i] + min(l[i],d[i]-d[par[i]]);
			for (int j = i+1; j <= n+1 && d[j] <= rb; j++)
			{
			   if (par[j] >= 0) continue;
			   par[j] = i;
			}
		}
		cout << (par[n+1] < 0 ? "NO" : "YES");
    cout << endl;
  }
  return 0;
}