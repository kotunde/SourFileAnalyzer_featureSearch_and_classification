#pragma comment(linker, "/STACK:10000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> T inline sqr(T x)
{
    return x * x;
}

#define pb push_back
#define mp make_pair
#define e1 first
#define e2 second
#define sz size

#define forn(i, n) for (i = 0; i < int(n); i++)
const ld pi = 3.1415926535897932384626433832795, eps = 1e-8;

const int maxn = 2050;
int nex[maxn];
int h[maxn];

void imp() 
{
	cout << "Impossible" << endl;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t, tt;
	cin >> tt;
	forn (t, tt)
	{
		int i, n;
		cin >> n;
		bool ok = true;
		cout << "Case #" << t + 1 << ": ";
	
		forn (i, n - 1)
		{
			cin >> nex[i];
			nex[i]--;
			if (nex[i] <= i)
			{
				ok = false;
				break;
			}
		}
		if (!ok)
		{
			imp;
			continue;
		}
		int u = 0;
		int inf = 1000000000;
		forn (i, n)
			h[i] = -1;
		while (u != n - 1)
		{
			h[u] = inf;
			u = nex[u];
		}
		h[n - 1] = inf;
		int l = 0, j, z;
		forn (i, n)
		{
			bool f = false;
			for (j = l + 1; j < n - 1; j++)
				if (h[j] == -1)
				{

					for (z = j + 1; z < n; z++)
						if (h[z] != -1)
							break;

					u = j;	
					while (u < z && h[u] == -1)
					{
						h[u] = h[z] - (i + 1) * (z - u);
						u = nex[u];
					}

					if (u != z)
					{
						ok = false;
						break;
					}

					f = true;
					break;
				}
			
			if (!ok)
				break;
			if (!f)
				break;
		}

		if (!ok)
		{
			imp();
			continue;
		}
		forn (i, n)
			cout << h[i] << " ";
		cout << endl;
	}
	return 0;
}
