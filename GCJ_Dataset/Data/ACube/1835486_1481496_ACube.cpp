#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout
string who = "oieastbg";
string wit = "01345789";
string s;
int k;
int in[256], out[256];
bool w[256][256];

void main2()
{
	cin >> k >> s;
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(w, 0, sizeof(w));
	int ed = 0;
	for (int i = 0; i < SIZE(s)-1; i++)
	{
		char a = s[i], b = s[i+1];
		int i1 = (who.find(a)!=(string::npos)), i2 = (who.find(b)!=(string::npos));
		int v1, v2;
		if (i1) v1 = wit[who.find(a)];
		if (i2) v2 = wit[who.find(b)];

		if (!w[a][b]) w[a][b] = 1, out[a]++, in[b]++, ed++;  

		if (i1 && i2 && !w[v1][v2]) w[v1][v2] = 1, out[v1]++, in[v2]++, ed++;

		if (i1 && !w[v1][b]) w[v1][b] = 1, out[v1]++, in[b]++, ed++;
		if (i2 && !w[a][v2]) w[a][v2] = 1, out[a]++, in[v2]++, ed++;
	}
	ed++;

	bool ok = 0;
	for (int i = 0; i < 256; i++)
		if (out[i] < in[i])
		{
		 	ok = 1;
		 	ed++;
		}
	ed -= ok;
	gout << ed << endl;
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
