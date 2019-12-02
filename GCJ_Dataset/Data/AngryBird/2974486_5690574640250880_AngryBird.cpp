#include <iostream>
#include <vector>

using namespace std;

void print(int r, int c, int k)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i < r-2) {
				cout << '*';
			}
			else {
				if (i == r-1 && j == c-1) {
					cout << 'c';
				}
				else if (j < k){
					cout << '*';
				}	
				else {
					cout << '.';
				}
			}
		}
		cout << endl;
	}
}

void print_c(int r, int c, int t) {
	int col = t/r, l = t - r*col;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i == r-1 && j == c-1) {
				cout << 'c';
			}
			else if (j > col) {
				cout << '.';
			}
			else if (j == col && i >= l) {
				cout << '.';
			}
			else {
				cout << '*';
			}
		}
		cout << endl;
	}
}

void print_r(int r, int c, int t)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (t > 0) {
				cout << '*';
				t--;
			}
			else if (i == r-1 && j == c-1) {
				cout << 'c';
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}
}

void check(int r, int c, int m)
{
	if (r*c == m+1){
		print_r(r, c, m);
	}
	else if (r == 1 || c == 1)
	{
		if (r*c < m+2)
			cout << "Impossible" << endl;
		else 
		{
			print_r(r, c, m);
		}
	}
	else {
		int k = (m+c-1)/c, l = (m+r-1)/r;
		if (k < r-1 && c-(m%c) > 1)
			print_r(r, c, m);
		else if (l < c-1 && r-(m%r) > 1)
			print_c(r, c, m);
		else {
			int t = m - c*(r-2);
			if (t%2 == 0 && t+4 <= c*2) {
				print(r, c, t/2);
			}
			else {
				cout << "Impossible" << endl;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int T;
	int R, C, M;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> R >> C >> M;
		cout << "Case #" << (i+1) << ":" << endl;
		check(R, C, M);
	}
	return 0;
}