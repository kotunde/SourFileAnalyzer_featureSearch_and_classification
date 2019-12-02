#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
bool F(pair <long long, long long > p1, pair <long long ,long long > p2)
{
	return (p1.first > p2.first);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test; cin >> test;
	for (int TEST = 1 ; TEST <= test; TEST++)
	{
		int n;		cin >> n;
		long long l,w; cin >> l >> w;
		vector<pair<long long, int>> r(n, make_pair(0, 0));		
		vector<pair<long long, long long>> point(n);
		for (int i = 0 ; i < n; i++)
		{
			cin >> r[i].first;
			r[i].second = i;
		}
		sort(r.begin(), r.end(), F);
		int last = 0;
		bool check = false;
		if (l < w)
			check = true;
		int mx = max(l,w);
		int mn = min(l,w);
		for (int i = 0 ; i < r.size(); i++)
		{			
			int p = r[i].second;		
			if (i == 0)
				point[p] = make_pair(0, 0);
			else
			{
				int add = point[r[i - 1].second].first;
				if (check)
					add = point[r[i - 1].second].second;
				if (r[i].first + r[i - 1].first + add > mx)
					break;
				point[p] = make_pair(r[i].first + r[i - 1].first + add, 0);
				if (check)
					swap(point[p].first ,point[p].second);
			}
			last = i + 1;
		}
		for (int i = last; i < r.size(); i++)
		{
			int p = r[i].second;
			if (i == r.size() - 1)
			{
				point[p] = make_pair(mx, mn);
				if (check)
					swap(point[p].first, point[p].second);
			}
			else
			{
				int add = point[r[i - 1].second].first;
				if (check)
					add = point[r[i - 1].second].second;
				point[p] = make_pair(add - r[i - 1].first- r[i].first, mn);
				if (check)
					swap(point[p].first, point[p].second);
			}
		}		
		cout << "Case #" << TEST <<": ";
		for (int i = 0 ; i < point.size(); i++)
			cout << point[i].first << ' ' << point[i].second << ' ';
		cout << '\n';
	}
	return 0;
}