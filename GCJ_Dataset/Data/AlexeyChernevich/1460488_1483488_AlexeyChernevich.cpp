#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
int get_next(int M, int len)
{
	return (M % 10) * len + M / 10;
}
int get_len(int k)
{
	int t = 1;
	k /= 10;
	while(k)
	{
		k /= 10;
		t *= 10;
	}
	return t;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	string tslate;
	for (int test = 0 ; test < n; test++)
	{
		int a, b, ans = 0;
		cout << "Case #" << test + 1 <<": ";
		cin >> a >> b;
		//cerr << "a b" << test<< '\n';
		for (int i = a ; i <= b; i++)
		{
			int len = get_len(i);
			int next = get_next(i, len);
			while (i !=next)
			{
				ans += i < next && next <= b;
				next = get_next(next, len);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}