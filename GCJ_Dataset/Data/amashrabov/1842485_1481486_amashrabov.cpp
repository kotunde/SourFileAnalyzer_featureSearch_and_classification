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
typedef int ld;
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
//const ld pi = 3.1415926535897932384626433832795, eps = 1e-8;

const int maxn = 10050;
ld d[maxn], l[maxn];
ld a[maxn];
typedef pair<double, int> T;
set<T> S;

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tt, t;
	cin >> tt;
	forn (t, tt)
	{
		int i, n;
		cin >> n;
		forn (i, n)
			cin >> d[i] >> l[i];
		ld w;
		cin >> w;
		forn (i, n)
			a[i] = 0;
		a[0] = min(d[0], l[0]);
		S.clear();
		S.insert(mp(a[0], 0));
		set<T>::iterator it;
		int cur;
		ld x;
		while (!S.empty())
		{
			it = S.end();
			it--;
			cur = it->e2;
			S.erase(it);
			forn (i, n)
			{
				if (abs(d[i] - d[cur]) <= a[cur])
				{
					x = l[i];
					if (a[i] < min(x, abs(d[i] - d[cur])))
					{
						S.erase(mp(a[i], i));
						a[i] = min(x, abs(d[i] - d[cur]));
						S.insert(mp(a[i], i));
					}
				}
			}
		}
		bool f = false;
		forn (i, n)
		{
			if (a[i] != 0)
			{
				if (abs(d[i] - w) <= a[i])
				{
					f = true;
					break;
				}
			}
		}
		cout << "Case #" << t + 1 << ": ";
		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}	
	return 0;
}
