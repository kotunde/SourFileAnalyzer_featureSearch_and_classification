#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
bool F(pair <long long, long long > p1, pair <long long ,long long > p2)
{
	return (p1.first < p2.first);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test; cin >> test;
	for (int TEST = 1 ; TEST <= test; TEST++)
	{
		int count ;
		cin >> count;
		vector<vector<bool>> vines(count + 1, vector<bool>(count + 1, false));
		vector<int> vlast(count + 1);
		vector<pair <long long, long long>> vp(count + 1);	
		vp[0].first = 0;
		vp[0].second = 0;
		for (int i = 1 ; i <= count; i++)
			cin >> vp[i].first >> vp[i].second;
		//vp[1].seocnd = vp[i].first;
		vines[0][1] = true;
		long long D;
		cin >> D;
		bool check = false;
		for (int i = 0 ; i <= count && !check; i++)
		{
			for (int j = i + 1 ; j <= count && !check; j++)
				if (vines[i][j])
				{
					long long len = min(vp[j].first - vp[i].first, vp[j].second);
					for (int t = max(vlast[j] + 1, j + 1); t <= count; t++)
						if (len >=  vp[t].first - vp[j].first)
						{
							vlast[j] = t;
							//if (vp[t].first - vp[j].first <= vp[t].second)
								vines[j][t] = true;
						}
						else
							break;
					if (len + vp[j].first >= D)
						check = true;
				}
		}
		string s = "NO";
		if (check)
			s = "YES";
		cout << "Case #" << TEST <<": " << s << '\n';		
	}
	return 0;
}