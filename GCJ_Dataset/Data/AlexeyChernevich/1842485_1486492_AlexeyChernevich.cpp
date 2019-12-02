#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test; cin >> test;
	for (int TEST = 1 ; TEST <= test; TEST++)
	{
		int n; cin >> n;
		vector<int> v(n - 1,0), p;
		for (int i = 0 ;i < n - 1; i++)
		{			
			cin >> v[i];
			v[i]--;
		}

		for (int i = 0 ; i < n; i++)
			p.push_back(i + 1);
		bool check = false;
		do
		{
			bool flag = true;
			for (int i = 0; i < (v.size() - 1) && flag; i++)
			{
				int last = v[i];
				for (int j = i + 1; j < last && flag; j++)
					flag = (p[i] > p[j]) && (p[last] > p[j]);
			}
			check = flag;
		}while(!check && next_permutation(p.begin(), p.end()));
		cout << "Case #" << TEST <<": "; 
		if (check == false)
		{
			cout << "Impossible\n";
			continue;
		}
		for (int i = 0 ; i < p.size(); i++)
			cout << p[i] << ' '; 
		cout << '\n';
	}
	return 0;
}