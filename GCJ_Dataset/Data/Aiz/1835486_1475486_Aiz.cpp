#include <iostream>
#include <algorithm>

using namespace std;

int l[1005], p[1005], ind[1005];

bool cmp(int i, int j)
{
	if (l[i] * p[j] != l[j] * p[i])
		return l[i] * p[j] < l[j] * p[i];
	return i < j;
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ":";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> l[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
			ind[i] = i;
		}
		sort(ind,ind+n,cmp);
		for (int i = 0; i < n; i++)
		{
			cout <<  " " << ind[i];
		}
    cout << endl;
  }
  return 0;
}