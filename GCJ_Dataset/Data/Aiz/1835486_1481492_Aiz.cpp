#include <iostream>
#include <algorithm>

using namespace std;

__int64 p[205], s[205], ind[205], x[205];
__int64 m, f, n;

bool cmp(int i, int j)
{
	if (p[i] != p[j])
		return p[i] < p[j];
	if (s[i] != s[j])
		return s[i] > s[j];              
	return i < j;
}

__int64 calc(__int64 cnt)
{
	__int64 res = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt <= x[ind[i]])
		{
			res += p[ind[i]] * cnt;
			return res;
		}
		res += p[ind[i]] * x[ind[i]];
	}
	throw 42;
}

bool ok(__int64 days)
{
	__int64 prod = ind[0];
	__int64 comnum = days / (s[prod] + 1);
	__int64 cntlast = days % (s[prod] + 1);
	__int64 last = 0;
	__int64 prev = prod;
	__int64 prleft = 0;
	__int64 prpr = 0;
	__int64 total = (comnum + (cntlast > 0)) * f + days * p[prod];
	for (int i = 1; i < n; i++)
	{
		__int64 used = 0;
		prod = ind[i];
		if (x[prod] == 0) continue;
		if (last)
		{
			if (comnum * x[prod] + prleft < cntlast)
			{
				prleft += comnum * x[prod];
				prpr += comnum * x[prod] * p[prod];
				prev = prod;
				continue;
			}
			else
			{
				if ((cntlast - prleft) * p[prod] + prpr >= calc(cntlast))
					break;
				total += (cntlast - prleft) * p[prod] + prpr;
				total -= calc(cntlast);
				used = cntlast - prleft;
				cntlast = 0;
			}
		}
		else if (cntlast > 0)
		{
			if (comnum * x[prod] < cntlast)
			{
				prleft = comnum * x[prod];
				prpr = comnum * x[prod] * p[prod];
				last = 1;
				prev = prod;
				continue;
			}
			if (cntlast * p[prod] >= calc(cntlast))
				break;
			total += cntlast * p[prod];
			total -= calc(cntlast);
			used = cntlast;
			cntlast = 0;
		}
		if (s[prev] * p[prod] >= calc(s[prev]))
			break;
		__int64 tokill = (comnum * x[prod] - used) / s[prod];
		total += tokill * s[prev] * p[prod];
		used += tokill * s[prev];
		comnum -= tokill;
		total -= tokill * calc(s[prev]);
		if (used > x[prod] * (comnum - 1))
		{
			comnum--;
			cntlast = s[prev] + used % x[prod];
			last = 0;
			prev = prod;
			continue;
		}
		comnum--;
		cntlast = s[prev];
		prleft = comnum * s[prod] - used;
		prpr = prleft * p[prod];
		last = 1;
		prev = prod;
	}
	return total <= m;
}

int main()
{
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
		cin >> m >> f >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i] >> s[i];
			ind[i] = i;
		}
		sort(ind,ind+n,cmp);
		__int64 z = -1;
		for (int i = 0; i < n; i++)
		{
			x[ind[i]] = max((__int64)0, s[ind[i]] - z);
			z += x[ind[i]];
		}
		__int64 l = 0, r = m+1;
		while (r-l > 1)
		{
			__int64 mid = (r+l)/2;
			if (ok(mid))
				l = mid;
			else
				r = mid;
		}
		cout << l;
    cout << endl;
  }
  return 0;
}