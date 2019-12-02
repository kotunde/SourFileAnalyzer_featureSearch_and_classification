#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

string s[10];
int n, m;
int mx, mxn;

vector<int> a[5];
set<string> ss;

int Count()
{
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		ss.clear();
		for(int j = 0; j < a[i].size(); j++)
		{
			int id = a[i][j];
			for(int k = 0; k < s[id].length(); k++)
			{
				ss.insert(s[id].substr(0, k+1));
			}
		}
		res += ss.size() + 1;
	}
	return res;
}

void func(int p)
{
	if(p == m)
	{ 
		for(int i = 0; i < n; i++)
		{
			if(a[i].size() == 0)
				return;
		}
		int res = Count();
		if(res > mx)
		{
			mx = res;
			mxn = 1;
		}
		else if(res == mx)
			mxn++;
		return;
	}
	for(int i = 0; i < n; i++)
	{
		a[i].push_back(p);
		func(p+1);
		a[i].pop_back();
	}
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);


	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);

		cin>>m>>n;
		for(int i = 0; i < m; i++)
			cin>>s[i];

		mx = mxn = 0;
		func(0);

		printf("%d %d\n", mx, mxn);
	}

	return 0;
}